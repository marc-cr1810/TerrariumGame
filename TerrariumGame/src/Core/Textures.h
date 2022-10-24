#pragma once

#include <Terrarium.h>

#include "Registry.h"

using namespace Terrarium;

class Textures
{
public:
	static void Init();

	static Ref<SubTexture2D> GetTexture(std::string texture) { return s_Registry.GetValue(texture); }
public:
	static Registry<Ref<SubTexture2D>> s_Registry;

	static Ref<Texture2D> s_GrassDirt;
};