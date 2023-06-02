#include "UBoat.h"

namespace assignment2
{
	UBoat::UBoat()
		: Vehicle(50)
	{
		Vehicle::mType = UBOAT;
	}

	UBoat::~UBoat()
	{
	}
	
	unsigned int UBoat::GetDiveSpeed() const
	{
		int x = static_cast<int>(GetPassengersTotalWeight());
		
		return static_cast<unsigned int>(500 * log((x + 150) / 150.0) + 30 + 0.5);
	}
	unsigned int UBoat::GetSailSpeed() const
	{
		int x = static_cast<int>(GetPassengersTotalWeight());
		double speed = 550 - x / 10.0;
		return speed > 200 ? static_cast<unsigned int>(speed + 0.5) : 200;
	}
	unsigned int UBoat::GetMaxSpeed() const
	{
		unsigned int sailSpeed = GetSailSpeed();
		unsigned int diveSpeed = GetDiveSpeed();

		return sailSpeed > diveSpeed ? sailSpeed : diveSpeed;
	}
}