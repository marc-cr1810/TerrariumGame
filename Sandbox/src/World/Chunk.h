#pragma once

#include <Terrarium.h>

#include "Cell.h"

#define CELLS_SIZE 16

extern class World;

class Chunk
{
public:
	Chunk();
	~Chunk() = default;

	void Update();
	void Render();

	void SetWorld(World* world, glm::vec2 position) { m_World = world; m_Position = position; }

	Cell* GetCell(uint32_t x, uint32_t y);
	void SetCell(Cell* cell, uint32_t x, uint32_t y);

	void IncActiveCells() { m_ActiveCells++; }
	void DecActiveCells() { m_ActiveCells--; }

	World* GetWorld() const { return m_World; }
	glm::vec2 GetPosition() const { return m_Position; }
	uint32_t GetActiveCells() const { return m_ActiveCells; }
private:
	Cell* m_Cells[CELLS_SIZE * CELLS_SIZE];
	glm::vec2 m_Position = { 0, 0 };
	World* m_World;
	uint32_t m_ActiveCells = 0;
};