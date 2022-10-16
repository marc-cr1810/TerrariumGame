#pragma once
#include "Material.h"

class AirMaterial : public Material
{
public:
	AirMaterial(uint32_t ID)
		: Material(ID)
	{
		m_Color = glm::vec4(0.0f);
		m_Mass = 0.00001f;
	}
};