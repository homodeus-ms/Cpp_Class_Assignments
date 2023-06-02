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

		/*

		Boatplane bp(GetMaxPassengersCount() + plane.GetMaxPassengersCount());

		unsigned int count = plane.GetPassengersCount();

		for (unsigned int i = 0; i < count; ++i)
		{
			Person* p = new Person(GetPassenger(i));
			RemovePassenger(i);
			bp.AddPassenger(p);
		}

		count = GetPassengersCount();

		for (unsigned int i = 0; i < count; ++i)
		{
			Person* p = new Person(GetPassenger(i));
			RemovePassenger(i);
			bp.AddPassenger(p);
		}

		return bp;

		*/
	}
	unsigned int Boat::GetSailSpeed() const
	{
		unsigned int x = GetPassengersTotalWeight();
		return CalSailSpeed(x, 10.0);
	}
	unsigned int Boat::GetMaxSpeed() const
	{
		return GetSailSpeed();
	}
}