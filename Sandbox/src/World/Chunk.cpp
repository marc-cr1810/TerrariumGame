#include "Chunk.h"

#include "Materials/Material.h"

Chunk::Chunk()
{
	for (uint32_t y = 0; y < CELLS_SIZE; y++)
	{
		for (uint32_t x = 0; x < CELLS_SIZE; x++)
		{
			Cell *cell = new Cell();
			cell->SetMaterial(Materials::Air);
			cell->SetChunk(this, { x, y });
			m_Cells[x + y * CELLS_SIZE] = cell;
		}
	}
}

void Chunk::Update()
{
	for (uint32_t cy = 0; cy < CELLS_SIZE; cy++)
	{
		for (uint32_t cx = 0; cx < CELLS_SIZE; cx++)
		{
			m_Cells[cx + cy * CELLS_SIZE]->Update({ m_Position.x, m_Position.y }, { cx, cy });
		}
	}
}

void Chunk::Render()
{
	glm::mat4 transform = glm::translate(glm::mat4(1.0f), { (float)m_Position.x, (float)m_Position.y, 0.0f });

	Terrarium::Renderer2D::DrawRect(transform, glm::vec4{ 0.2f, 0.8f, 0.3f, 1.0f } * glm::vec4(0.5f));

	for (uint32_t cy = 0; cy < CELLS_SIZE; cy++)
	{
		for (uint32_t cx = 0; cx < CELLS_SIZE; cx++)
		{
			m_Cells[cx + cy * CELLS_SIZE]->Render({ m_Position.x, m_Position.y }, { cx, cy });
		}
	}
}

Cell* Chunk::GetCell(uint32_t x, uint32_t y)
{
	if (m_Cells == nullptr)
		return nullptr;

	if (x >= 0 && x < CELLS_SIZE && y >= 0 && y < CELLS_SIZE)
	{
		return m_Cells[x + y * CELLS_SIZE];
	}
	return nullptr;
}

void Chunk::SetCell(Cell* cell, uint32_t x, uint32_t y)
{
	if (cell == nullptr)
		return;

	if (x >= 0 && x < CELLS_SIZE && y >= 0 && y < CELLS_SIZE)
	{
		m_Cells[x + y * CELLS_SIZE]->CopyFrom(cell);
	}
}
