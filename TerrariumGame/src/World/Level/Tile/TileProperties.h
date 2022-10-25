#pragma once

#include "World/Level/Material/Material.h"

class TileProperties
{
public:
	TileProperties(Material* material);

	static TileProperties* From(Material* material);
	TileProperties* NoCollision();
	TileProperties* Air();

	Material* GetMaterial() const { return m_Material; }
	bool HasCollision() const { return m_HasCollision; }
	bool IsAir() const { return m_IsAir; }
private:
	Material* m_Material;
	bool m_HasCollision;
	bool m_IsAir;
};