#include "FlatLevelGenerator.h"

#include "World/Level/Level.h"

void FlatLevelGenerator::Generate(Level* level)
{
	for (int y = 0; y < LEVEL_CHUNKS_HEIGHT * CHUNK_TILES_HEIGHT; y++)
	{
		for (int x = 0; x < LEVEL_CHUNKS_WIDTH * CHUNK_TILES_WIDTH; x++)
		{
			if (y == m_Height)
			{
				level->SetTile(TilePos(x, y), Tiles::Get("grass"));
			}
			else if (y > (m_Height - 2) && y < m_Height)
			{
				level->SetTile(TilePos(x, y), Tiles::Get("dirt"));
			}
			else if (y <= (m_Height - 2))
			{
				level->SetTile(TilePos(x, y), Tiles::Get("stone"));
			}
		}
	}
}
