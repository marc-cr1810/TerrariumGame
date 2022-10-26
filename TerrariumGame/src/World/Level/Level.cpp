#include "Level.h"

Level::Level()
{

}

Chunk Level::GetChunkAt(TilePos tilePos) const
{
	return GetChunk(tilePos.GetChunkX(), tilePos.GetChunkY());
}

Chunk Level::GetChunk(int x, int y) const
{
	return m_Chunks[x][y];
}

Tile Level::GetTile(TilePos tilePos) const
{
	Chunk chunk = GetChunkAt(tilePos);
	return chunk.GetTile(tilePos.GetChunkTileX(), tilePos.GetChunkTileY());
}

void Level::SetTile(TilePos tilePos, Tile tile)
{
	int x = tilePos.GetChunkTileX();
	int y = tilePos.GetChunkTileY();
	int chunkX = tilePos.GetChunkX();
	int chunkY = tilePos.GetChunkY();
	m_Chunks[chunkX][chunkY].SetTile(x, y, tile);
}

void Level::Render()
{
	// For now chunk and level will have a render function.
	// This will be changed in the future for a separate rendering system.

	for (int y = 0; y < LEVEL_CHUNKS_HEIGHT; y++)
	{
		for (int x = 0; x < LEVEL_CHUNKS_WIDTH; x++)
		{
			m_Chunks[x][y].Render(x, y);
		}
	}
}
