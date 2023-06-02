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
				
		return static_cast<unsigned int>(200 * pow(EULERS_NUMBER, (800 - x) / 500.0) + 0.5);
	}
	unsigned int Airplane::GetDriveSpeed() const
	{
		int x = static_cast<int>(GetPassengersTotalWeight());

		return static_cast<unsigned int>(4 * pow(EULERS_NUMBER, (400 - x) / 70.0) + 0.5);
	}
	unsigned int Airplane::GetMaxSpeed() const
	{
		return GetFlySpeed();
	}

	Boatplane Airplane::operator+(Boat& boat)
	{
		Boatplane bp(GetMaxPassengersCount() + boat.GetMaxPassengersCount());

		unsigned int count = GetPassengersCount();

		for (unsigned int i = 0; i < count; ++i)
		{
			Person* p = new Person(GetPassenger(0));
			RemovePassenger(0);
			bp.AddPassenger(p);
		}

		count = boat.GetPassengersCount();

		for (unsigned int i = 0; i < count; ++i)
		{
			Person* p = new Person(boat.GetPassenger(0));
			boat.RemovePassenger(0);
			bp.AddPassenger(p);
		}

		return bp;
	}
}