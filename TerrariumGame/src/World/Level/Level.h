#pragma once

#include "World/Level/Chunk.h"
#include "World/Level/Tile/TilePos.h"
#include "World/Level/Generation/Generator.h"

#define LEVEL_CHUNKS_WIDTH 6
#define LEVEL_CHUNKS_HEIGHT 6

class Level
{
public:
	Level();
	Level(uint32_t seed);

	void Generate();

	void SetGenerator(Generator* generator) { m_Generator = generator; }

	Chunk GetChunkAt(TilePos tilePos) const;
	Chunk GetChunk(int x, int y) const;

	Tile GetTile(TilePos tilePos) const;
	void SetTile(TilePos tilePos, Tile tile);

	uint32_t GetSeed() const { return m_Seed; }

	void Render();
private:
	uint32_t m_Seed;

	Chunk m_Chunks[LEVEL_CHUNKS_WIDTH][LEVEL_CHUNKS_HEIGHT];
	Generator* m_Generator;
};