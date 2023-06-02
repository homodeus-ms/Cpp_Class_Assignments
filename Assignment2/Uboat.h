#pragma once

#include "IDivable.h"
#include "ISailable.h"

#include "Vehicle.h"

namespace assignment2
{
	class UBoat : public Vehicle, public IDivable, public ISailable
	{
	public:
		UBoat();
		virtual ~UBoat();

		unsigned int GetSailSpeed() const;
		unsigned int GetDiveSpeed() const;
		unsigned int GetMaxSpeed() const;
	};
}