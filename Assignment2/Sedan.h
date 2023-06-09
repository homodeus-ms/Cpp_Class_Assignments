#pragma once

#include "IDrivable.h"
#include "Vehicle.h"
#include "Trailer.h"

namespace assignment2
{
	class Trailer;

	class Sedan : public Vehicle, public IDrivable
	{
	public:
		Sedan();
		virtual ~Sedan();
		Sedan(const Sedan& other);
		Sedan& operator=(const Sedan& other);

		bool AddTrailer(const Trailer* trailer);
		bool RemoveTrailer();

		unsigned int GetDriveSpeed() const;
		unsigned int GetMaxSpeed() const;
		
	private:
		const Trailer* mTrailer = nullptr;
	};
}