#include "Material.h"

#include "Air.h"
#include "Dirt.h"
#include "Sand.h"
#include "Water.h"

// The default material used to handle cells out of bounds
Material* Materials::Null = new NullMaterial();

Material* Materials::Air = new AirMaterial(0);
Material* Materials::Dirt = new DirtMaterial(1);
Material* Materials::Sand = new SandMaterial(2);
Material* Materials::Water = new WaterMaterial(3);

Material::Material()
	: m_ID(-1), m_Color({ 0.0f, 0.0f, 0.0f, 0.0f })
{
}

Material::Material(uint32_t ID)
	: m_ID(ID), m_Color({ 0.0f, 0.0f, 0.0f, 0.0f })
{
}

void Material::RunPhysics(Cell* cell, glm::vec2 chunkPos, glm::vec2 cellPos)
{
	// By default all cells make sure that their active state is false
	cell->SetActive(false);
}

bool Material::operator==(const Material& other)
{
	if (m_ID == other.GetID())
		return true;
	return false;
}
