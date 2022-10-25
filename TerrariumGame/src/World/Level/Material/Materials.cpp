#include "Materials.h"

#include "MaterialBuilder.h"

Registry<Material*> Materials::s_Registry = Registry<Material*>("material");

void Materials::Init()
{
	s_Registry.Register("air", MaterialBuilder().NonSolid()->Build());

	s_Registry.Register("dirt", MaterialBuilder().Build());
	s_Registry.Register("grass", MaterialBuilder().Build());

	s_Registry.Register("stone", MaterialBuilder().Build());
}
