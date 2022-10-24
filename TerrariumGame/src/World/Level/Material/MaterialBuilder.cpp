#include "MaterialBuilder.h"

Material* MaterialBuilder::Build()
{
	return new Material(this->m_Flammable, this->m_Solid, this->m_Liquid, this->m_Air);
}

MaterialBuilder* MaterialBuilder::Flammable()
{
	m_Flammable = true;
	return this;
}

MaterialBuilder* MaterialBuilder::NonSolid()
{
	m_Solid = false;
	return this;
}

MaterialBuilder* MaterialBuilder::Liquid()
{
	m_Liquid = true;
	return this;
}

MaterialBuilder* MaterialBuilder::Air()
{
	m_Air = true;
	return this;
}
