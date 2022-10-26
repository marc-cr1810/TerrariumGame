#include "Level.h"

Level::Level()
{

}

void Level::Render()
{
	// For now chunk and level will have a render function.
	// This will be changed in the future for a separate rendering system.

	for (int y = 0; y < LEVEL_CHUNK_HEIGHT; y++)
	{
		for (int x = 0; x < LEVEL_CHUNK_WIDTH; x++)
		{
			m_Chunks[x][y].Render(x, y);
		}
	}
}
