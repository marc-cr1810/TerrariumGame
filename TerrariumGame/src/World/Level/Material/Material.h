#pragma once

class Material
{
public:
	Material(bool flammable, bool solid, bool liquid)
		: m_Flammable(flammable), m_Solid(solid), m_Liquid(liquid)
	{}
private:
	bool m_Flammable;
	bool m_Solid;
	bool m_Liquid;
};