#pragma once

#include "ISailable.h"
#include "Vehicle.h"

#include "Boatplane.h"

namespace assignment2
{
	class Airplane;

	class Boat : public Vehicle, public ISailable
	{
	public:
		Boat(unsigned int maxPassengersCount);
		virtual ~Boat();

		unsigned int GetSailSpeed() const;
		unsigned int GetMaxSpeed() const;

		Boatplane operator+(Airplane& plane);
	};
}
