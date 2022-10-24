#pragma once

#include <string>

class Tile
{
public:
	Tile(std::string ID);

	void Render();

	std::string GetID() const { return m_ID; }
private:
	std::string m_ID;
};