#pragma once

#include "IFlyable.h"
#include "IDrivable.h"

#include "Boatplane.h"
#include "Vehicle.h"

namespace assignment2
{
	class Boat;

	class Airplane : public Vehicle, public IFlyable, public IDrivable
	{
	public:
		Airplane(unsigned int maxPassengersCount);
		virtual ~Airplane();

		unsigned int GetFlySpeed() const;
		unsigned int GetDriveSpeed() const;
		unsigned int GetMaxSpeed() const;

		Boatplane operator+(Boat& boat);
	};
}