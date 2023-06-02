#pragma once

#include "Person.h"
#include "eTransportType.h"

namespace assignment2
{
	class Vehicle
	{
	public:
		Vehicle(unsigned int maxPassengersCount);
		virtual ~Vehicle();

		Vehicle(const Vehicle& other);
		Vehicle& operator=(const Vehicle& other);

		virtual unsigned int GetMaxSpeed() const = 0;

		bool AddPassenger(const Person* person);
		bool RemovePassenger(unsigned int i);
		const Person* GetPassenger(unsigned int i) const;
		unsigned int GetPassengersCount() const;
		unsigned int GetMaxPassengersCount() const;
		unsigned int GetPassengersTotalWeight() const;

		eTransportType GetType() const;

	private:
		unsigned int mCurrPassengersCount;
		unsigned int mMaxPassengersCount;
		const Person** mPassengers;
		unsigned int mPassengersTotalWeight;

	protected:
		eTransportType mType;
	};
}