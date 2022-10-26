#include "LevelGenerator.h"

#include "Noise.h"

#include "World/Level/Level.h"

void LevelGenerator::Generate(Level* level)
{
	int heightmap[LEVEL_CHUNKS_WIDTH * CHUNK_TILES_WIDTH];

	NoiseSettings noiseSettings(level->GetSeed(), 9, 0.65f);
	NoiseGenerator noiseGen(noiseSettings);

	for (int i = 0; i < LEVEL_CHUNKS_WIDTH * CHUNK_TILES_WIDTH; i++)
	{
		float noise = noiseGen.GetNoise(i, 0);
		heightmap[i] = 100 * noise;
		TE_TRACE(heightmap[i]);
	}

	for (int y = 0; y < LEVEL_CHUNKS_HEIGHT * CHUNK_TILES_HEIGHT; y++)
	{
		for (int x = 0; x < LEVEL_CHUNKS_WIDTH * CHUNK_TILES_WIDTH; x++)
		{
			if (y == heightmap[x])
			{
				level->SetTile(TilePos(x, y), Tiles::Get("grass"));
			}
			else if (y > (heightmap[x] - 2) && y < heightmap[x])
			{
				level->SetTile(TilePos(x, y), Tiles::Get("dirt"));
			}
			else if (y <= (heightmap[x] - 2))
			{
				level->SetTile(TilePos(x, y), Tiles::Get("stone"));
			}
		}
	}
}
