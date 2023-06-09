#include "Boat.h"
#include "Boatplane.h"
#include "Airplane.h"

namespace assignment2
{
	Boat::Boat(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
		Vehicle::mType = BOAT;
	}

	Boat::~Boat()
	{
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		return plane + *this;
	}
	unsigned int Boat::GetSailSpeed() const
	{
		int x = GetPassengersTotalWeight();
		return CalSailSpeed(x, 10.0);
	}
	unsigned int Boat::GetMaxSpeed() const
	{
		return GetSailSpeed();
	}
}