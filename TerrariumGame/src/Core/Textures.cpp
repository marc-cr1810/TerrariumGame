#include "Textures.h"

Registry<Ref<SubTexture2D>> Textures::s_Registry = Registry<Ref<SubTexture2D>>("texture");

Ref<Texture2D> Textures::s_GrassDirt = NULL;
Ref<Texture2D> Textures::s_Stone = NULL;

void Textures::Init()
{
	if (!s_GrassDirt)
		s_GrassDirt = Texture2D::Create("assets/textures/tiles/grass_dirt.png");
	if (!s_Stone)
		s_Stone = Texture2D::Create("assets/textures/tiles/stone.png");

	s_Registry.Register("dirt", SubTexture2D::CreateFromCoords(s_GrassDirt, { 0, 0 }, { 8, 8 }));
	s_Registry.Register("grass", SubTexture2D::CreateFromCoords(s_GrassDirt, { 1, 0 }, { 8, 8 }));

	s_Registry.Register("stone", SubTexture2D::CreateFromCoords(s_Stone, { 0, 0 }, { 8, 8 }));
}
