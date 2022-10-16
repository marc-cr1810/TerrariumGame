#pragma once

#include <glm/glm.hpp>
#include <Terrarium.h>

extern class Cell;

class Material
{
public:
	Material();
	Material(uint32_t ID);

	uint32_t GetID() const { return m_ID; }
	glm::vec4 GetColor() const { return m_Color; }
	float GetMass() const { return m_Mass; }

	virtual void RunPhysics(Cell* cell, glm::vec2 chunkPos, glm::vec2 cellPos);

	bool operator==(const Material& other);
protected:
	uint32_t m_ID;
	glm::vec4 m_Color;
	float m_Mass;
};

class Materials
{
public:
	static Material* Null;

	static Material* Air;
	static Material* Dirt;
	static Material* Sand;
	static Material* Water;
};

class NullMaterial : public Material
{
public:
	NullMaterial()
	: Material(-1)
	{
		m_Color = glm::vec4(0.0f);
		m_Mass = 10000.0f;
	}
};