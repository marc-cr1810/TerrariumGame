#pragma once

#include <Terrarium.h>

#include "Material.h"
#include "../Cell.h"

class SandMaterial : public Material
{
public:
	SandMaterial(uint32_t ID)
		: Material(ID)
	{
		m_Color = glm::vec4{ 0.76f, 0.70f, 0.50f, 1.0f };
	}

	void RunPhysics(Cell* cell, glm::vec2 chunkPos, glm::vec2 cellPos) override
	{
		if (cell->GetNeighborCell(0, -1)->GetMaterial() == Materials::Air)
		{
			cell->Move(0, -1);
		}
		else if (cell->GetNeighborCell(-1, -1)->GetMaterial() == Materials::Air)
		{
			cell->Move(-1, -1);
		}
		else if (cell->GetNeighborCell(1, -1)->GetMaterial() == Materials::Air)
		{
			cell->Move(1, -1);
		}
	}
};