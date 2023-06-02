#pragma once

#include <cmath>

constexpr auto EULER_NUMBER = (2.71828182845904523536028747135266249);

inline unsigned int CalPlaneSpeed(int x, int a, int b, double c)
{
	return static_cast<unsigned int>(a * pow(EULER_NUMBER, (b - x) / c) + 0.5);
}

namespace assignment2
{
	class IFlyable
	{
	public:
		virtual unsigned int GetFlySpeed() const = 0;
	};
}