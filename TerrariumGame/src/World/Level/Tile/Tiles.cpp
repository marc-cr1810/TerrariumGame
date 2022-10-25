#include "Tiles.h"

#include "World/Level/Material/Materials.h"

Registry<Tile> Tiles::s_Registry = Registry<Tile>("tile");

void Tiles::Init()
{
	Register("air", TileProperties::From(Materials::Get("air"))->NoCollision()->Air());

	Register("dirt", TileProperties::From(Materials::Get("dirt")));
	Register("grass", TileProperties::From(Materials::Get("grass")));
	
	Register("stone", TileProperties::From(Materials::Get("stone")));
}

Tile Tiles::Register(std::string id, TileProperties* properties)
{
	Tile tile = s_Registry.Register(id, Tile(id, properties));
	return tile;
}
