#pragma once

#include "Material.h"

class DirtMaterial : public Material
{
public:
	DirtMaterial(uint32_t ID)
		: Material(ID)
	{
		m_Color = glm::vec4{ 0.46f, 0.33f, 0.17f, 1.0f };
	}
};