#pragma once
#include "Material.h"

#include "Core/Registry.h"

class Materials
{
public:
	static void Init();
	static Material* Get(std::string material) { return s_Registry.GetValue(material); }
private:
	static Registry<Material*> s_Registry;
};