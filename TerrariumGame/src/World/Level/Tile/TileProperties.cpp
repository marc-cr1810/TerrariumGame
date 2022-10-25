#include "TileProperties.h"

TileProperties::TileProperties(Material* material)
{
	m_Material = material;
	m_HasCollision = true;
	m_IsAir = false;
}

TileProperties* TileProperties::From(Material* material)
{
	return new TileProperties(material);
}

TileProperties* TileProperties::NoCollision()
{
	this->m_HasCollision = false;
	return this;
}

TileProperties* TileProperties::Air()
{
	this->m_IsAir = true;
	return this;
}
