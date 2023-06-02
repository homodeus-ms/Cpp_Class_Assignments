#include "DeusExMachina.h"

namespace assignment2
{
	DeusExMachina* DeusExMachina::mInstance = nullptr;

	DeusExMachina* DeusExMachina::GetInstance()
	{
		if (mInstance == nullptr)
		{
			mInstance = new DeusExMachina;
		}

		return mInstance;
	}
	DeusExMachina::~DeusExMachina()
	{
		delete mInstance;
	}

	void DeusExMachina::Travel() const
	{
		for (unsigned int i = 0; i < mCurrVehicles; ++i)
		{
			eTransportType type = mVehicles[i]->GetType();
			unsigned int turnValue = mMovingData.turn[i];

			switch (type)
			{
			case PLANE:
				if (turnValue % 4 == 0)
				{
					mInstance->mMovingData.movingCount[i]++;
				}
				break;

			case BOAT:
				if (turnValue % 3 < 2)
				{
					mInstance->mMovingData.movingCount[i]++;
				}
				break;

			case AUTOMOBILE:
				if (turnValue % 6 != 5)
				{
					mInstance->mMovingData.movingCount[i]++;
				}
				break;

			case AUTOMOBILE_WITH_TRAILER:
				if (turnValue % 7 < 5)
				{
					mInstance->mMovingData.movingCount[i]++;
				}
				break;

			case UBOAT:
				if (turnValue % 6 < 2)
				{
					mInstance->mMovingData.movingCount[i]++;
				}
				break;

			default:
				assert(0);
				break;
			}

			mInstance->mMovingData.turn[i]++;
		}
	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{
		if (mCurrVehicles == 10)
		{
			return false;
		}

		mVehicles[mCurrVehicles] = vehicle;
		mMovingData.movingCount[mCurrVehicles] = 0;
		mMovingData.turn[mCurrVehicles++] = 0;

		return true;
	}

	bool DeusExMachina::RemoveVehicle(unsigned int i)
	{
		if (i >= mCurrVehicles)
		{
			return false;
		}

		delete mVehicles[i];
		mVehicles[i] = nullptr;

		for (unsigned int idx = i; idx < mCurrVehicles - 1; ++idx)
		{
			mVehicles[idx] = mVehicles[idx + 1];
			mMovingData.movingCount[idx] = mMovingData.movingCount[idx + 1];
			mMovingData.turn[idx] = mMovingData.turn[idx + 1];
		}

		mVehicles[--mCurrVehicles] = nullptr;
		mMovingData.movingCount[mCurrVehicles] = 0;
		mMovingData.turn[mCurrVehicles] = 0;

		return true;
	}

	const Vehicle* DeusExMachina::GetFurthestTravelled() const
	{
		if (mCurrVehicles == 0)
		{
			return NULL;
		}

		bool bNotTravelled = true;

		for (unsigned int i = 0; i < mCurrVehicles; ++i)
		{
			if (mMovingData.turn[i] != 0)
			{
				bNotTravelled = false;
				break;
			}
		}

		if (bNotTravelled == true)
		{
			return mVehicles[0];
		}

		unsigned int furthestTravelledIdx = 0;
		unsigned int furthestTravelledDistance = mMovingData.movingCount[0] * mVehicles[0]->GetMaxSpeed();

		for (unsigned int i = 1; i < mCurrVehicles; ++i)
		{
			unsigned int travelledDistance = mMovingData.movingCount[i] * mVehicles[i]->GetMaxSpeed();

			if (furthestTravelledDistance < travelledDistance)
			{
				furthestTravelledDistance = travelledDistance;
				furthestTravelledIdx = i;
			}
		}

		return mVehicles[furthestTravelledIdx];
	}
	DeusExMachina::DeusExMachina()
		: mCurrVehicles(0)
	{
		memset(mVehicles, 0, sizeof(mVehicles));
	}
	DeusExMachina::DeusExMachina(const DeusExMachina& other)
		: mCurrVehicles(other.mCurrVehicles)
	{
		memcpy(mVehicles, other.mVehicles, sizeof(mVehicles));
	}
	
	DeusExMachina DeusExMachina::operator=(const DeusExMachina& other)
	{
		return *mInstance;
	}

}