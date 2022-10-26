#pragma once

#include "World/Level/Tile/Tiles.h"

extern class Level;

class Generator
{
public:
	Generator() = default;

	virtual void Generate(Level* level);
private:

};