#include "World.h"

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

	for (uint32_t y = minY; y < maxY; y++)
	{
		for (uint32_t x = minX; x < maxX; x++)
		{
			m_Chunks[x + y * m_Width]->Render();
		}
	}
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
