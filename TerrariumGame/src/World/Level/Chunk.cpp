#include "Chunk.h"

#include "World/Level/Tile/Tiles.h"

Chunk::Chunk()
{
	for (int y = 0; y < CHUNK_TILES_HEIGHT; y++)
	{
		for (int x = 0; x < CHUNK_TILES_WIDTH; x++)
		{
			m_Tiles[x][y] = Tiles::Get("air");
		}
	}
}
