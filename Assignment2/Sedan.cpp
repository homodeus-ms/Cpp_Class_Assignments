#include "Sedan.h"

namespace assignment2
{
	Sedan::Sedan()
		: Vehicle(4), mTrailer(nullptr)
	{
		Vehicle::mType = AUTOMOBILE;
	}
	Sedan::Sedan(const Sedan& other)
		: Vehicle(other)
	{
	    mTrailer = new Trailer(other.mTrailer->GetWeight());
	}
	Sedan& Sedan::operator=(const Sedan& other)
	{
		Vehicle::operator=(other);

		if (mTrailer == nullptr)
		{
			mTrailer = new Trailer(other.mTrailer->GetWeight());
		}
		else
		{
			delete mTrailer;
			mTrailer = new Trailer(other.mTrailer->GetWeight());
		}

		return *this;
	}

	Sedan::~Sedan()
	{
		delete mTrailer;
	}

	bool Sedan::AddTrailer(const Trailer* trailer)
	{
		if (trailer == nullptr || mTrailer != nullptr)
		{
			return false;
		}

		mTrailer = trailer;

		Vehicle::mType = AUTOMOBILE_WITH_TRAILER;
		
		return true;
	}

	bool Sedan::RemoveTrailer()
	{
		if (mTrailer == nullptr)
		{
			return false;
		}

		delete mTrailer;
		mTrailer = nullptr;

		Vehicle::mType = AUTOMOBILE;

		return true;
	}
	unsigned int Sedan::GetDriveSpeed() const
	{
		unsigned int x = GetPassengersTotalWeight();
		
		x = mTrailer == nullptr ? x : x + mTrailer->GetWeight();

		if (x > 350)
		{
			return 300;
		}
		if (x > 260)
		{
			return 380;
		}
		if (x > 160)
		{
			return 400;
		}
		if (x > 80)
		{
			return 458;
		}

		return 480;
	}
	unsigned int Sedan::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}
}