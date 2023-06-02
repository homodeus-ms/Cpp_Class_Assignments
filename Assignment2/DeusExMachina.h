#pragma once

#include <cassert>

#include "Vehicle.h"
#include "MovingData.h"

namespace assignment2
{
	class DeusExMachina
	{
	public:
		static DeusExMachina* GetInstance();
		void Travel() const;
		bool AddVehicle(Vehicle* vehicle);
		bool RemoveVehicle(unsigned int i);
		const Vehicle* GetFurthestTravelled() const;
		~DeusExMachina();

	private:
		DeusExMachina();
		DeusExMachina(const DeusExMachina& other);
		DeusExMachina operator=(const DeusExMachina& other);
		//~DeusExMachina();

		static DeusExMachina* mInstance;

		Vehicle* mVehicles[MAX_VEHICLES];
		unsigned int mCurrVehicles;

		MovingData mMovingData = { 0, };
	};
}