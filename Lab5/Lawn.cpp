#include "Lawn.h"

namespace lab5
{
	Lawn::Lawn()
		: mArea(0)
	{
	}

	Lawn::~Lawn()
	{
	}
	unsigned int Lawn::GetGrassPrice(eGrassType grassType) const
	{
		return static_cast<unsigned int>((mArea * grassType) / 100.0 + 0.5);
	}
	unsigned int Lawn::GetMinimumSodRollsCount() const
	{
		return mArea % 3 == 0 ? static_cast<unsigned int>(mArea * 10 / 3.0) : static_cast<unsigned int>(mArea * 10 / 3.0 + 1);
	}
}