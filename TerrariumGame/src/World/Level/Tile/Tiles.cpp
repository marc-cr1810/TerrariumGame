#include "Tiles.h"

Registry<Tile> Tiles::s_Registry = Registry<Tile>("tile");

void Tiles::Init()
{
	Register("dirt");
	Register("grass");
}

Tile Tiles::Register(std::string id)
{
	Tile tile = s_Registry.Register(id, Tile(id));
	return tile;
}
