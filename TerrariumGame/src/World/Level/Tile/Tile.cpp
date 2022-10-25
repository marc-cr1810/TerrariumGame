#include "Tile.h"

#include <Terrarium.h>

#include "Core/Textures.h"

using namespace Terrarium;

Tile::Tile(std::string ID)
	: m_ID(ID)
{}

void Tile::Render(glm::vec3 pos)
{
	Renderer2D::DrawQuad(glm::translate(glm::mat4(1.0f), pos), Textures::Get(m_ID));
}
