#pragma once

#include <Terrarium.h>

#include "Chunk.h"

class World
{
public:
	World(uint32_t width, uint32_t height);
	~World();

	void Update(glm::vec3 cameraPos, glm::vec2 size);
	void Render(glm::vec3 cameraPos, glm::vec2 size);

	Chunk* GetChunk(glm::vec2 position) const;
	Cell* GetCell(glm::vec2 position) const;
private:
	Chunk **m_Chunks;
	uint32_t m_Width;
	uint32_t m_Height;
};