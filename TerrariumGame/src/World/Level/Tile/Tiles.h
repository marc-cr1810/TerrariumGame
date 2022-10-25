#pragma once
#include "Tile.h"

#include "Core/Registry.h"

#include "TileProperties.h"

class Tiles
{
public:
	static void Init();

	static Tile Register(std::string id, TileProperties* properties);

	static Tile Get(std::string tile) { return s_Registry.GetValue(tile); }
private:
	static Registry<Tile> s_Registry;
};