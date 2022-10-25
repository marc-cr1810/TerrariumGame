#pragma once

#include "Material.h"

class MaterialBuilder
{
public:
	MaterialBuilder()
		: m_Flammable(false), m_Solid(true), m_Liquid(false)
	{}

	Material* Build();

	MaterialBuilder* Flammable();
	MaterialBuilder* NonSolid();
	MaterialBuilder* Liquid();
private:
	bool m_Flammable;
	bool m_Solid;
	bool m_Liquid;
};