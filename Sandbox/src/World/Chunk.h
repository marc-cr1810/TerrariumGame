#pragma once

#include <Terrarium.h>

#include "Cell.h"

#define CELLS_SIZE 16

class Chunk
{
public:
	Chunk();
	~Chunk() = default;

	void Update(uint32_t x, uint32_t y);
	void Render(uint32_t x, uint32_t y);

	Cell* GetCell(uint32_t x, uint32_t y);
private:
	Cell *m_Cells[CELLS_SIZE * CELLS_SIZE];
};