#pragma once

#include <Terrarium.h>

#include "Registry.h"

using namespace Terrarium;

class Textures
{
public:
	static void Init();

	static Ref<SubTexture2D> Get(std::string texture) { return s_Registry.GetValue(texture); }
public:
	static Ref<Texture2D> s_GrassDirt;
private:
	static Registry<Ref<SubTexture2D>> s_Registry;
};