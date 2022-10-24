#pragma once

class Material
{
public:
	Material(bool flammable, bool solid, bool liquid, bool air)
		: m_Flammable(flammable), m_Solid(solid), m_Liquid(liquid), m_Air(air)
	{}
private:
	bool m_Flammable;
	bool m_Solid;
	bool m_Liquid;
	bool m_Air;
};