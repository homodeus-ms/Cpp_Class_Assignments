#include "Motorcycle.h"

#define MIN_SPEED_WEIGHT (131)

namespace assignment2
{
	Motorcycle::Motorcycle()
		: Vehicle(2)
	{
		Vehicle::mType = AUTOMOBILE;
	}

	Motorcycle::~Motorcycle()
	{
	}
	unsigned int Motorcycle::GetDriveSpeed() const
	{
		unsigned int x = GetPassengersTotalWeight();

		return x < MIN_SPEED_WEIGHT ? static_cast<unsigned int>(-1 * pow((x / 15.0), 3) + 2 * x + 400 + 0.5) : 0;
	}
	unsigned int Motorcycle::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}
}