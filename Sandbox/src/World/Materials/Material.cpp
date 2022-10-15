#include "Material.h"

#include "Air.h"
#include "Dirt.h"
#include "Sand.h"

// The default material used to handle cells out of bounds
Material* Materials::Null = new NullMaterial();

Material* Materials::Air = new AirMaterial(0);
Material* Materials::Dirt = new DirtMaterial(1);
Material* Materials::Sand = new SandMaterial(2);

Material::Material()
	: m_ID(-1), m_Color({ 0.0f, 0.0f, 0.0f, 0.0f })
{
}

Material::Material(uint32_t ID)
	: m_ID(ID), m_Color({ 0.0f, 0.0f, 0.0f, 0.0f })
{
}

bool Material::operator==(const Material& other)
{
	if (m_ID == other.GetID())
		return true;
	return false;
}
