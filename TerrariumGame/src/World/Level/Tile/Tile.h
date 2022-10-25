#pragma once

#include <string>
#include <glm/glm.hpp>

#include "TileProperties.h"

class Tile
{
public:
	Tile() = default;
	Tile(std::string ID, TileProperties* properties);

	void Render(glm::vec3 pos = { 0.0f, 0.0f, 0.0f });

	std::string GetID() const { return m_ID; }
private:
	std::string m_ID;
	TileProperties* m_Properties;
};