#include "Cell.h"

#include "Chunk.h"
#include "World.h"

void Cell::Update(glm::vec2 chunkPos, glm::vec2 cellPos)
{
	m_Material->RunPhysics(this, chunkPos, cellPos);
}

void Cell::Render(glm::vec2 chunkPos, glm::vec2 cellPos)
{
	if (m_Material->GetColor().a == 0.0f)
		return;

	glm::vec3 scale = { 1.0f / CELLS_SIZE, 1.0f / CELLS_SIZE, 1.0f };
	glm::vec3 pos = { chunkPos.x + (cellPos.x * scale.x) - 0.5f, chunkPos.y + (cellPos.y * scale.y - 0.5f), 0.0f };

	pos += glm::vec3{ scale.x * 0.5f, scale.y * 0.5f, 0.0f };

	glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * glm::scale(glm::mat4(1.0f), scale);
	Terrarium::Renderer2D::DrawQuad(transform, m_Material->GetColor());
}

void Cell::SetMaterial(Material* material)
{
	m_Material = material;
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
	cell->m_Chunk = other->m_Chunk;
	cell->m_Material = other->m_Material;
	cell->m_Position = other->m_Position;
	return cell;
}

void Cell::CopyFrom(Cell* other)
{
	m_Material = other->m_Material;
}

Cell* Cell::GetNeighborCell(int x, int y)
{
	World* world = m_Chunk->GetWorld();

	glm::vec2 chunkPos = m_Chunk->GetPosition();
	glm::vec2 cellPos = { m_Position.x + x, m_Position.y + y };

	return world->GetCell(chunkPos, cellPos);
}