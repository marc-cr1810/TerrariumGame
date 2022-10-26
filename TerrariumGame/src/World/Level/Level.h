#pragma once

#include "World/Level/Chunk.h"
#include "World/Level/Tile/TilePos.h"

#define LEVEL_CHUNKS_WIDTH 3
#define LEVEL_CHUNKS_HEIGHT 2

class Level
{
public:
	Level();

	Chunk GetChunkAt(TilePos tilePos) const;
	Chunk GetChunk(int x, int y) const;

	Tile GetTile(TilePos tilePos) const;
	void SetTile(TilePos tilePos, Tile tile);

	void Render();
private:
	Chunk m_Chunks[LEVEL_CHUNKS_WIDTH][LEVEL_CHUNKS_HEIGHT];
};