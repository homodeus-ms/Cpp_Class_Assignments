#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"

namespace assignment2
{
	Airplane::Airplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
		Vehicle::mType = PLANE;
	}

	Airplane::~Airplane()
	{
	}
	unsigned int Airplane::GetFlySpeed() const
	{
		int x = static_cast<int>(GetPassengersTotalWeight());
		
		return CalPlaneSpeed(x, 200, 800, 500.0);
	}
	unsigned int Airplane::GetDriveSpeed() const
	{
		int x = static_cast<int>(GetPassengersTotalWeight());

		return CalPlaneSpeed(x, 4, 400, 70.0);
	}
	unsigned int Airplane::GetMaxSpeed() const
	{
		unsigned int flySpeed = GetFlySpeed();
		unsigned int driveSpeed = GetDriveSpeed();

		return flySpeed > driveSpeed ? flySpeed : driveSpeed;
	}

	Boatplane Airplane::operator+(Boat& boat)
	{
		Boatplane bp(GetMaxPassengersCount() + boat.GetMaxPassengersCount());

		unsigned int count = GetPassengersCount();

		for (unsigned int i = 0; i < count; ++i)
		{
			Person* p = new Person(*GetPassenger(0));
			RemovePassenger(0);
			bp.AddPassenger(p);
		}

		count = boat.GetPassengersCount();

		for (unsigned int i = 0; i < count; ++i)
		{
			Person* p = new Person(*(boat.GetPassenger(0)));
			boat.RemovePassenger(0);
			bp.AddPassenger(p);
		}

		return bp;
	}
}