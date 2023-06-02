#include "Boatplane.h"

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
		Vehicle::mType = PLANE;
	}

	Boatplane::~Boatplane()
	{
	}

	unsigned int Boatplane::GetFlySpeed() const
	{
		int x = static_cast<int>(GetPassengersTotalWeight());
		return static_cast<unsigned int>(150 * pow(EULERS_NUMBER, (500 - x) / 300.0) + 0.5);
	}
	unsigned int Boatplane::GetSailSpeed() const
	{
		int x = static_cast<int>(GetPassengersTotalWeight());
		return CalSailSpeed(x, 1.7);
	}
	unsigned int Boatplane::GetMaxSpeed() const
	{
		return GetFlySpeed();
	}
}