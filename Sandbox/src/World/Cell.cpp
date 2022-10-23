#include "Cell.h"

#include "Chunk.h"
#include "World.h"

void Cell::Update(glm::vec2 chunkPos, glm::vec2 cellPos)
{
	m_Material->RunPhysics(this, chunkPos, cellPos);
}

void Cell::SetMaterial(Material* material)
{
	m_Material = material;
	if (m_Chunk != nullptr)
		SetActive(true);
}

void Cell::Move(int x, int y)
{
	World* world = m_Chunk->GetWorld();
	
	Cell* other = Copy(GetNeighborCell(x, y));
	Cell* self = Copy(this);
	
	SetNeighborCell(self, x, y);
	world->SetCell(other, m_Chunk->GetPosition(), m_Position);
}

Material* Cell::GetMaterial() const
{
	if (this == nullptr)
		return Materials::Null;
	return m_Material;
}

void Cell::SetNeighborCell(Cell* cell, int x, int y)
{
	World* world = m_Chunk->GetWorld();

	glm::vec2 chunkPos = m_Chunk->GetPosition();
	glm::vec2 cellPos = { m_Position.x + x, m_Position.y + y };

	world->SetCell(cell, chunkPos, cellPos);
}

Cell* Cell::Copy(Cell* other)
{
	Cell* cell = new Cell();
	if (other != nullptr)
	{
		cell->m_Chunk = other->m_Chunk;
		cell->m_Material = other->m_Material;
		cell->m_Position = other->m_Position;
		cell->m_Active = other->m_Active;
	}
	return cell;
}

void Cell::CopyFrom(Cell* other)
{
	m_Material = other->m_Material;
	m_Active = other->m_Active;
}

void Cell::SetActive(bool active)
{
	if (this == nullptr)
		return;
	if (m_Active == active)
		return;
	m_Active = active;

	if (m_Active)
	{
		m_Chunk->IncActiveCells();

		Cell* left = GetNeighborCell(1, 0);
		Cell* right = GetNeighborCell(-1, 0);
		Cell* above = GetNeighborCell(0, 1);
		Cell* below = GetNeighborCell(0, -1);
		if (left != nullptr) if (!left->m_Chunk->GetActiveCells() > 0)
			left->SetActive(true);
		if (right != nullptr) if (!right->m_Chunk->GetActiveCells() > 0)
			right->SetActive(true);
		if (above != nullptr) if (!above->m_Chunk->GetActiveCells() > 0)
			above->SetActive(true);
		if (below != nullptr) if (!below->m_Chunk->GetActiveCells() > 0)
			below->SetActive(true);
	}
	else
		m_Chunk->DecActiveCells();
}

bool Cell::GetActive()
{
	if (this == nullptr)
		return false;
	return m_Active;
}

Cell* Cell::GetNeighborCell(int x, int y)
{
	World* world = m_Chunk->GetWorld();

	glm::vec2 chunkPos = m_Chunk->GetPosition();
	glm::vec2 cellPos = { m_Position.x + x, m_Position.y + y };

	return world->GetCell(chunkPos, cellPos);
}