#include "TilePos.h"

#include "World/Level/Chunk.h"

TilePos::TilePos(int x, int y)
	: m_X(x), m_Y(y)
{
	m_ChunkX = std::trunc(x / CHUNK_TILES_WIDTH);
	m_ChunkY = std::trunc(y / CHUNK_TILES_HEIGHT);
}

int TilePos::GetChunkTileX() const
{
	return m_X - (m_ChunkX * CHUNK_TILES_WIDTH);
}

int TilePos::GetChunkTileY() const
{
	return m_Y - (m_ChunkY * CHUNK_TILES_HEIGHT);
}
