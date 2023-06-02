#pragma once

#include <cmath>

#define EULERS_NUMBER (2.7182818284590452353602874713527)

inline unsigned int CalPlaneSpeed(int x, int a, int b, double c)
{
	return static_cast<unsigned int>((a * pow(EULERS_NUMBER, (b - x) / c) + 0.5));
}

namespace assignment2
{
	class IFlyable
	{
	public:
		virtual unsigned int GetFlySpeed() const = 0;
	};
}