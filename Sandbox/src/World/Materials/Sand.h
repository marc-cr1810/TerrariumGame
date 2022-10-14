#pragma once

#include <Terrarium.h>

#include "Material.h"

class SandMaterial : public Material
{
public:
	SandMaterial(uint32_t ID)
		: Material(ID)
	{
		m_Color = glm::vec4{ 0.76f, 0.70f, 0.50f, 1.0f };
	}

	void RunPhysics(glm::vec2 chunkPos, glm::vec2 cellPos) override
	{

	}
};