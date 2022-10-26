#pragma once
#include "World/Level/Generation/Generator.h"

class FlatLevelGenerator : public Generator
{
public:
	FlatLevelGenerator(int height = 10)
		: m_Height(height)
	{}

	void Generate(Level* level) override;
private:
	int m_Height;
};