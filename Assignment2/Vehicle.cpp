#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount)
		: mMaxPassengersCount(maxPassengersCount)
		, mCurrPassengersCount(0), mPassengersTotalWeight(0), mType(DEFAULT)
	{
		mPassengers = new const Person*[mMaxPassengersCount];
	}

	Vehicle::~Vehicle()
	{
		for (unsigned int i = 0; i < mCurrPassengersCount; ++i)
		{
			delete mPassengers[i];
			mPassengers[i] = nullptr;
		}

		delete[] mPassengers;
		
		mPassengersTotalWeight = 0;
	}

	Vehicle::Vehicle(const Vehicle& other)
		: mMaxPassengersCount(other.GetMaxPassengersCount()), mType(other.GetType())
		, mCurrPassengersCount(other.GetPassengersCount()), mPassengersTotalWeight(other.GetPassengersTotalWeight())
	{
		mPassengers = new const Person*[mMaxPassengersCount];

		for (unsigned int i = 0; i < mCurrPassengersCount; ++i)
		{
			const Person* p = new const Person(*(other.mPassengers[i]));
			mPassengers[i] = p;
		}
	}

	Vehicle& Vehicle::operator=(const Vehicle& other)
	{
		bool bNewGenerated = false;

		if (mMaxPassengersCount < other.GetMaxPassengersCount())
		{
			delete[] mPassengers;
			mPassengers = new const Person * [other.GetMaxPassengersCount()];
			bNewGenerated = true;
		}

		mType = other.GetType();
		mCurrPassengersCount = other.GetPassengersCount(); 
		mPassengersTotalWeight = other.GetPassengersTotalWeight();

		for (unsigned int i = 0; i < other.mCurrPassengersCount; ++i)
		{
			const Person* p = new const Person(*(other.mPassengers[i]));

			if (bNewGenerated == false)
			{
				delete mPassengers[i];
			}
			
			mPassengers[i] = p;
		}

		return *this;
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		if (mCurrPassengersCount == mMaxPassengersCount)
		{
			return false;
		}

		mPassengers[mCurrPassengersCount++] = person;

		mPassengersTotalWeight += person->GetWeight();

		return true;
	}

	bool Vehicle::RemovePassenger(unsigned int i)
	{
		if (i >= mCurrPassengersCount)
		{
			return false;
		}

		mPassengersTotalWeight -= mPassengers[i]->GetWeight();

		delete mPassengers[i];
		mPassengers[i] = nullptr;

		for (unsigned int idx = i; idx < mCurrPassengersCount - 1; ++idx)
		{
			mPassengers[idx] = mPassengers[idx + 1];
		}
		mPassengers[--mCurrPassengersCount] = nullptr;

		return true;
	}

	unsigned int Vehicle::GetPassengersCount() const
	{
		return mCurrPassengersCount;
	}

	unsigned int Vehicle::GetMaxPassengersCount() const
	{
		return mMaxPassengersCount;
	}

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		if (i >= mCurrPassengersCount)
		{
			return NULL;
		}

		return mPassengers[i];
	}
	unsigned int Vehicle::GetPassengersTotalWeight() const
	{
		return mPassengersTotalWeight;
	}

	eTransportType Vehicle::GetType() const
	{
		return mType;
	}
}