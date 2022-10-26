#pragma once

#include "World/Level/Tile/Tile.h"

#define CHUNK_TILES_WIDTH	16
#define CHUNK_TILES_HEIGHT	16

class Chunk
{
public:
	Chunk();

	void Render(int x = 0, int y = 0);

	Tile GetTile(int x, int y) const { return m_Tiles[x][y]; }
	void SetTile(int x, int y, Tile tile) { m_Tiles[x][y] = tile; }
private:
	Tile m_Tiles[CHUNK_TILES_WIDTH][CHUNK_TILES_HEIGHT];
};