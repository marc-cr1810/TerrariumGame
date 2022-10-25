#pragma once

#include <string>

#include "World/Level/Material/Material.h"

#include <glm/glm.hpp>

class Tile
{
public:
	Tile() = default;
	Tile(std::string ID);

	void Render(glm::vec3 pos = { 0.0f, 0.0f, 0.0f });

	std::string GetID() const { return m_ID; }
private:
	std::string m_ID;
	Material* m_Material;
};