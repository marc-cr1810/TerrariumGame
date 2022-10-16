#pragma once

#include <Terrarium.h>

#include "Materials/Material.h"

extern class Chunk;

class Cell
{
public:
	Cell() = default;

	void Update(glm::vec2 chunkPos, glm::vec2 cellPos);
	void Render(glm::vec2 chunkPos, glm::vec2 cellPos);

	void SetMaterial(Material* material);
	void SetChunk(Chunk* chunk, glm::vec2 position) { m_Chunk = chunk; m_Position = position; }

	void Move(int x, int y);

	Material* GetMaterial() const;

	Cell* GetNeighborCell(int x, int y);
	void SetNeighborCell(Cell* cell, int x, int y);

	Cell* Copy(Cell* other);
	void CopyFrom(Cell* other);

	void SetActive(bool active);
	bool GetActive();
private:
	Material* m_Material = Materials::Null;
	Chunk* m_Chunk;
	glm::vec2 m_Position = { 0.0f, 0.0f };
	bool m_Active;
};