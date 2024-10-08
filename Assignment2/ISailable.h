#pragma once

inline unsigned int CalSailSpeed(int totalWeight, double coefficient)
{
	return (800 - coefficient * totalWeight) > 20 ? static_cast<unsigned int>((800 - coefficient * totalWeight) + 0.5) : 20;
}

namespace assignment2
{
	class ISailable
	{
	public:
		virtual unsigned int GetSailSpeed() const = 0;
	};
}