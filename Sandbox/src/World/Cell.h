#pragma once

#include <Terrarium.h>

#include "Materials/Material.h"

class Cell
{
public:
	Cell() = default;

	void Update(glm::vec2 chunkPos, glm::vec2 cellPos);
	void Render(glm::vec2 chunkPos, glm::vec2 cellPos);

	void SetMaterial(Material* material);
private:
	Material* m_Material;
};