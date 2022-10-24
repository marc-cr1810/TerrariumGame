#pragma once

#include "Material.h"

class MaterialBuilder
{
public:
	MaterialBuilder()
		: m_Flammable(false), m_Solid(true), m_Liquid(false), m_Air(false)
	{}

	Material* Build();

	MaterialBuilder* Flammable();
	MaterialBuilder* NonSolid();
	MaterialBuilder* Liquid();
	MaterialBuilder* Air();
private:
	bool m_Flammable;
	bool m_Solid;
	bool m_Liquid;
	bool m_Air;
};