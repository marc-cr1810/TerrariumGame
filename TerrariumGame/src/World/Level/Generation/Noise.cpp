#include "Noise.h"

#include <cmath>

NoiseSettings::NoiseSettings(uint32_t seed, int octaves, float persistence)
    : m_NumOctaves(octaves), m_Persistence(persistence)
{
    m_Primes[0] = rand();
    m_Primes[1] = rand();
    m_Primes[2] = rand();
}

float NoiseGenerator::GetNoise(int x, int y)
{
    float total = 0;
    float frequency = pow(2, m_Settings.Octaves());
    float amplitude = 1;
    for (int i = 0; i < m_Settings.Octaves(); ++i) {
        frequency /= 2;
        amplitude *= m_Settings.Persistence();
        total += InterpolatedNoise(x / frequency, y / frequency) * amplitude;
    }
    return total / frequency;
}

float NoiseGenerator::Noise(int x, int y)
{
    int n = x + y * 57;
    n = (n << 13) ^ n;
    int a = m_Settings.Prime(0), b = m_Settings.Prime(1), c = m_Settings.Prime(2);
    int t = (n * (n * n * a + b) + c) & 0x7fffffff;
    return 1.0 - (float)(t) / 1073741824.0;
}

float NoiseGenerator::SmoothedNoise(int x, int y)
{
    float corners = (Noise(x - 1, y - 1) + Noise(x + 1, y - 1) + Noise(x - 1, y + 1) + Noise(x + 1, y + 1)) / 16;
    float sides = (Noise(x - 1, y) + Noise(x + 1, y) + Noise(x, y - 1) + Noise(x, y + 1)) / 8;
    float center = Noise(x, y) / 4;
    return corners + sides + center;
}

float NoiseGenerator::Interpolate(float a, float b, float x)
{
    float ft = x * 3.1415927;
    float f = (1 - std::cos(ft)) * 0.5;
    return  a * (1 - f) + b * f;
}

float NoiseGenerator::InterpolatedNoise(int x, int y)
{
    int integerX = x;
    float fractionalX = x - integerX;
    int integerY = y;
    float fractionalY = y - integerY;

    float v1 = SmoothedNoise(integerX, integerY),
        v2 = SmoothedNoise(integerX + 1, integerY),
        v3 = SmoothedNoise(integerX, integerY + 1),
        v4 = SmoothedNoise(integerX + 1, integerY + 1),
        i1 = Interpolate(v1, v2, fractionalX),
        i2 = Interpolate(v3, v4, fractionalX);
    return Interpolate(i1, i2, fractionalY);
}
