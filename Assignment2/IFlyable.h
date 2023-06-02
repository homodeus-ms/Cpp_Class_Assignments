#pragma once

#include <math.h>

#define EULERS_NUMBER (2.7182818284590452353602874713527)

inline unsigned int CalFlySpeed(unsigned int x, unsigned int a, unsigned int b, double c)
{
	return static_cast<unsigned int>((a * pow(EULERS_NUMBER, static_cast<int>(b - x) / c) + 0.5));
}

namespace assignment2
{
	class IFlyable
	{
	public:
		virtual unsigned int GetFlySpeed() const = 0;
	};
}