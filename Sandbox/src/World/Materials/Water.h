#pragma once

#include <Terrarium.h>

#include "Material.h"
#include "../Cell.h"
#include "../../Utils/Random.h"

class WaterMaterial : public Material
{
public:
	WaterMaterial(uint32_t ID)
		: Material(ID)
	{
		m_Color = glm::vec4{ 0.26f, 0.76f, 0.90f, 0.80f };
		m_Mass = 0.5f;
	}

	void RunPhysics(Cell* cell, glm::vec2 chunkPos, glm::vec2 cellPos) override
	{
		Cell* left = cell->GetNeighborCell(-1, 0);
		Cell* right = cell->GetNeighborCell(1, 0);

		if (cell->GetNeighborCell(0, -1)->GetMaterial()->GetMass() < GetMass())
		{
			cell->Move(0, -1);
			return;
		}
		else if (left->GetMaterial() == Materials::Air || right->GetMaterial() == Materials::Air)
		{
			uint32_t dir = std::rand() & 1 ? 0 : 1;

			if (dir)
			{
				if (right->GetMaterial() == Materials::Air)
					cell->Move(1, 0);
				return;
			}
			else
			{
				if (left->GetMaterial() == Materials::Air)
					cell->Move(-1, 0);
				return;
			}
		}

		Material::RunPhysics(cell, chunkPos, cellPos);
	}
};