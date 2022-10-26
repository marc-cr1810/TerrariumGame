#pragma once

#include "Chunk.h"

#define LEVEL_CHUNK_WIDTH 3
#define LEVEL_CHUNK_HEIGHT 2

class Level
{
public:
	Level();

	void Render();
private:
	Chunk m_Chunks[LEVEL_CHUNK_WIDTH][LEVEL_CHUNK_HEIGHT];
};