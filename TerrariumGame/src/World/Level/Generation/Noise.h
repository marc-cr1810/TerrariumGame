#pragma once

#include <cstdint>

struct NoiseSettings
{
public:
	NoiseSettings(uint32_t seed, int octaves = 7, float persistence = 0.5f);

	int Prime(int i) const { return m_Primes[i]; }
	int Octaves() const { return m_NumOctaves; }
	float Persistence() const { return m_Persistence; }
private:
	int m_Primes[3] = { 362489573, 795918041, 350777237 };
	int m_NumOctaves;
	float m_Persistence;
};

class NoiseGenerator
{
public:
	NoiseGenerator(NoiseSettings settings)
		: m_Settings(settings)
	{}

	float GetNoise(int x, int y);
private:
	float Noise(int x, int y);
	float SmoothedNoise(int x, int y);
	float Interpolate(float a, float b, float x);	// Cosine interpolation
	float InterpolatedNoise(int x, int y);
private:
	NoiseSettings m_Settings;
};