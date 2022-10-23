#include "World.h"

namespace Utils {

	static uint32_t ConvertToRGBA(const glm::vec4& color)
	{
		uint8_t r = (uint8_t)(color.r * 255.0f);
		uint8_t g = (uint8_t)(color.g * 255.0f);
		uint8_t b = (uint8_t)(color.b * 255.0f);
		uint8_t a = (uint8_t)(color.a * 255.0f);

		uint32_t result = (a << 24) | (b << 16) | (g << 8) | r;
		return result;
	}

}

World::World(uint32_t width, uint32_t height)
{
	m_Width = width;
	m_Height = height;
	m_Chunks = new Chunk*[m_Width * m_Height];

	for (uint32_t y = 0; y < m_Height; y++)
	{
		for (uint32_t x = 0; x < m_Width; x++)
		{
			Chunk* chunk = new Chunk();
			chunk->SetWorld(this, { x, y });
			m_Chunks[x + y * m_Width] = chunk;
		}
	}
}

World::~World()
{
	//delete[] m_Chunks; <- Keep getting an error?!?
}

void World::Update(glm::vec3 cameraPos, glm::vec2 size)
{
	cameraPos += glm::vec3{ 1.0f, -1.0f, 0.0f };

	int minX = std::clamp((int)std::round(cameraPos.x) - (int)(size.x * 0.5f), 0, (int)m_Width - 1);
	int maxX = std::clamp((int)std::round(cameraPos.x) + (int)(size.x * 0.5f), 0, (int)m_Width - 1);
	int minY = std::clamp((int)std::round(cameraPos.y) - (int)(size.y * 0.5f), 0, (int)m_Height - 1);
	int maxY = std::clamp((int)std::round(cameraPos.y) + (int)(size.y * 0.5f), 0, (int)m_Height - 1);

	for (uint32_t y = minY; y < maxY; y++)
	{
		for (uint32_t x = minX; x < maxX; x++)
		{
			if (m_Chunks[x + y * m_Width]->GetActiveCells() > 0)
				m_Chunks[x + y * m_Width]->Update();
		}
	}
}

void World::Render(glm::vec3 cameraPos, glm::vec2 size)
{
	cameraPos += glm::vec3{1.0f, -1.0f, 0.0f};

	int minX = std::clamp((int)std::round(cameraPos.x) - (int)(size.x * 0.5f), 0, (int)m_Width - 1);
	int maxX = std::clamp((int)std::round(cameraPos.x) + (int)(size.x * 0.5f), 0, (int)m_Width - 1);
	int minY = std::clamp((int)std::round(cameraPos.y) - (int)(size.y * 0.5f), 0, (int)m_Height - 1);
	int maxY = std::clamp((int)std::round(cameraPos.y) + (int)(size.y * 0.5f), 0, (int)m_Height - 1);

	OnResize(m_Width * CELLS_SIZE, m_Height * CELLS_SIZE);

	for (uint32_t y = minY; y < maxY; y++)
	{
		for (uint32_t x = minX; x < maxX; x++)
		{
			//m_Chunks[x + y * m_Width]->Render();
			for (uint32_t cy = 0; cy < CELLS_SIZE; cy++)
			{
				for (uint32_t cx = 0; cx < CELLS_SIZE; cx++)
				{
					glm::vec4 color = m_Chunks[x + y * m_Width]->GetCell(cx, cy)->GetMaterial()->GetColor();
					m_ImageData[((x * CELLS_SIZE) + cx) + ((y * CELLS_SIZE) + cy) * m_WorldImage->GetWidth()] = Utils::ConvertToRGBA(color);
				}
			}
		}
	}

	m_WorldImage->SetData(m_ImageData, sizeof(m_ImageData));
	glm::mat4 transform = glm::translate(glm::mat4(1.0f), { m_Width / 2, m_Height / 2, 0.0f }) * glm::scale(glm::mat4(1.0f), { m_Width, m_Height, 1.0f });
	Terrarium::Renderer2D::DrawQuad(transform, m_WorldImage);
}

void World::SetCell(Cell* cell, glm::vec2 chunkPos, glm::vec2 cellPos)
{
	if (cellPos.y < 0)
	{
		chunkPos += glm::vec2{ 0.0f, -1.0f };
		cellPos = glm::vec2{ cellPos.x, CELLS_SIZE + cellPos.y };
	}
	else if (cellPos.y >= CELLS_SIZE)
	{
		chunkPos += glm::vec2{ 0.0f, 1.0f };
		cellPos = glm::vec2{ cellPos.x, CELLS_SIZE - cellPos.y };
	}

	if (cellPos.x < 0)
	{
		chunkPos += glm::vec2{ -1.0f, 0.0f };
		cellPos = glm::vec2{ CELLS_SIZE + cellPos.x, cellPos.y };
	}
	else if (cellPos.x >= CELLS_SIZE)
	{
		chunkPos += glm::vec2{ 1.0f, 0.0f };
		cellPos = glm::vec2{ CELLS_SIZE - cellPos.x, cellPos.y };
	}

	Chunk* chunk = GetChunk(chunkPos);
	chunk->SetCell(cell, cellPos.x, cellPos.y);
}

Chunk* World::GetChunk(glm::vec2 position) const
{
	uint32_t x = std::round(position.x);
	uint32_t y = std::round(position.y);

	if (x >= 0 && x < m_Width && y >= 0 && y <= m_Height)
		return m_Chunks[x + y * m_Width];
	return nullptr;
}

Cell* World::GetCell(glm::vec2 position) const
{
	Chunk* chunk = GetChunk(position);

	float x = position.x + 0.5f;
	float y = position.y + 0.5f;

	float cx = std::round((float)CELLS_SIZE * (float)(x - ((long)(x))));
	float cy = std::round((float)CELLS_SIZE * (float)(y - ((long)(y))));

	return chunk->GetCell(cx, cy);
}

Cell* World::GetCell(glm::vec2 chunkPos, glm::vec2 cellPos) const
{
	if (cellPos.y < 0)
	{
		chunkPos += glm::vec2{ 0.0f, -1.0f };
		cellPos = glm::vec2{ cellPos.x, CELLS_SIZE + cellPos.y };
	}
	else if (cellPos.y >= CELLS_SIZE)
	{
		chunkPos += glm::vec2{ 0.0f, 1.0f };
		cellPos = glm::vec2{ cellPos.x, CELLS_SIZE - cellPos.y };
	}

	if (cellPos.x < 0)
	{
		chunkPos += glm::vec2{ -1.0f, 0.0f };
		cellPos = glm::vec2{ CELLS_SIZE + cellPos.x, cellPos.y };
	}
	else if (cellPos.x >= CELLS_SIZE)
	{
		chunkPos += glm::vec2{ 1.0f, 0.0f };
		cellPos = glm::vec2{ CELLS_SIZE - cellPos.x, cellPos.y };
	}

	Chunk* chunk = GetChunk(chunkPos);
	return chunk->GetCell(cellPos.x, cellPos.y);
}

void World::OnResize(uint32_t width, uint32_t height)
{
	// Check if an image has been created
	if (m_WorldImage)
	{
		// Ignore if the image does not need to be resized
		if (m_WorldImage->GetWidth() == width && m_WorldImage->GetHeight() == height)
			return;

		// Resize the image
		//m_WorldImage->Resize(width, height);
	}
	else
	{
		// Create the image
		m_WorldImage = Terrarium::Texture2D::Create(width, height);
	}

	// Make the image data array
	delete[] m_ImageData;
	m_ImageData = new uint32_t[width * height];
}
