#pragma once

struct TilePos
{
public:
	TilePos(int x, int y);

	int GetX() const { return m_X; }
	int GetY() const { return m_Y; }
	int GetChunkX() const { return m_ChunkX; }
	int GetChunkY() const { return m_ChunkY; }
	int GetChunkTileX() const;
	int GetChunkTileY() const;
private:
	int m_X, m_Y;
	int m_ChunkX, m_ChunkY;
};