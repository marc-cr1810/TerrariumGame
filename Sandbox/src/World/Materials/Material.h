#pragma once

#include <glm/glm.hpp>
#include <Terrarium.h>

class Material
{
public:
	Material();
	Material(uint32_t ID);

	glm::vec4 GetColor() const { return m_Color; }
	uint32_t GetID() const { return m_ID; }

	virtual void RunPhysics(glm::vec2 chunkPos, glm::vec2 cellPos) { }

	bool operator==(const Material& other);
protected:
	uint32_t m_ID;
	glm::vec4 m_Color;
};

class Materials
{
public:
	static Material* Air;
	static Material* Dirt;
	static Material* Sand;
};