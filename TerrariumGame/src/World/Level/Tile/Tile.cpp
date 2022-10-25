#include "Tile.h"

#include <Terrarium.h>

#include "Core/Textures.h"

using namespace Terrarium;

Tile::Tile(std::string ID, TileProperties* properties)
	: m_ID(ID), m_Properties(properties)
{}

void Tile::Render(glm::vec3 pos)
{
	if (m_Properties->IsAir())
		return;

	Renderer2D::DrawQuad(glm::translate(glm::mat4(1.0f), pos), Textures::Get(m_ID));
}
