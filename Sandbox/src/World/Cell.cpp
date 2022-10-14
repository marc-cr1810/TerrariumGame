#include "Cell.h"

#include "Chunk.h"

void Cell::Update(glm::vec2 chunkPos, glm::vec2 cellPos)
{
	m_Material->RunPhysics(chunkPos, cellPos);
}

void Cell::Render(glm::vec2 chunkPos, glm::vec2 cellPos)
{
	if (m_Material->GetColor().a == 0.0f)
		return;

	glm::vec3 scale = { 1.0f / CELLS_SIZE, 1.0f / CELLS_SIZE, 1.0f };
	glm::vec3 pos = { chunkPos.x + (cellPos.x * scale.x) - 0.5f, -(chunkPos.y + (cellPos.y * scale.y) - 0.5f), 0.0f };

	pos += glm::vec3{ scale.x * 0.5f, -scale.y * 0.5f, 0.0f };

	glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * glm::scale(glm::mat4(1.0f), scale);
	Terrarium::Renderer2D::DrawQuad(transform, m_Material->GetColor());
}

void Cell::SetMaterial(Material* material)
{
	m_Material = material;
}
