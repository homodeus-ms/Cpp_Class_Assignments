#pragma once

#include "IFlyable.h"
#include "ISailable.h"

#include "Vehicle.h"

namespace assignment2
{
	class Boatplane : public Vehicle, public IFlyable, public ISailable 
	{
	public:
		Boatplane(unsigned int maxPassengersCount);
		~Boatplane();

		unsigned int GetFlySpeed() const;
		unsigned int GetSailSpeed() const;
		unsigned int GetMaxSpeed() const;
	};
}
