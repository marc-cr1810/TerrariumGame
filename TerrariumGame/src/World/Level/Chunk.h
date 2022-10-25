#pragma once

#include "World/Level/Tile/Tile.h"

#define CHUNK_TILES_WIDTH	16
#define CHUNK_TILES_HEIGHT	16

class Chunk
{
public:
	Chunk();
public:
	Tile m_Tiles[CHUNK_TILES_WIDTH][CHUNK_TILES_HEIGHT];
};