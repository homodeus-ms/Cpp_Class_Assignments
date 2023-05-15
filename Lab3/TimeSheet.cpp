#include "TimeSheet.h"
#include <cmath>

namespace lab3
{
	TimeSheet::TimeSheet(const char* name, unsigned int maxEntries)
		: mMaxEntries(maxEntries)
		, mNameLength(strlen(name))
		, mIndex(0)
		, mName(name)
	{
		mWorkTime = new int[mMaxEntries];
		memset(mWorkTime, 0, mMaxEntries * sizeof(int));
	}

	TimeSheet::TimeSheet(const TimeSheet& other)
		: mMaxEntries(other.mMaxEntries)
		, mNameLength(other.mNameLength)
		, mIndex(other.mIndex)
		, mName(other.mName)
	{
		mWorkTime = new int[mMaxEntries];
		memcpy(mWorkTime, other.mWorkTime, mMaxEntries * sizeof(int));
	}

	TimeSheet::~TimeSheet()
	{
		delete[] mWorkTime;
	}
	TimeSheet& TimeSheet::operator=(const TimeSheet& rhs)
	{
		mName = rhs.mName;
		mMaxEntries = rhs.mMaxEntries;
		memcpy(mWorkTime, rhs.mWorkTime, mMaxEntries * sizeof(int));
		mNameLength = rhs.mNameLength;
		mIndex = rhs.mIndex;

		return *this;
	}
	void TimeSheet::AddTime(int timeInHours)
	{
		if (timeInHours >= 1 && timeInHours <= 10 && mIndex < mMaxEntries)
		{
			mWorkTime[mIndex] = timeInHours;
			mIndex++;
		}
	}

	int TimeSheet::GetTimeEntry(unsigned int index) const
	{
		if (index >= mMaxEntries)
		{
			return -1;
		}
		return mWorkTime[index] == 0 ? -1 : mWorkTime[index];
	}

	int TimeSheet::GetTotalTime() const
	{
		unsigned int result = 0;
		for (int i = 0; i < static_cast<int>(mIndex); ++i)
		{
			result += mWorkTime[i];
		}

		return result;
	}

	float TimeSheet::GetAverageTime() const
	{
		if (mIndex == 0)
		{
			return 0.0f;
		}
		int sum = GetTotalTime();
		float average = sum / static_cast<float>(mIndex);
		return average;
	}

	float TimeSheet::GetStandardDeviation() const
	{
		if (mIndex == 0)
		{
			return 0.0f;
		}
		float averageSquareX;
		int sumSquareX = 0;
		int sum = 0;
		float average;
		float sDeviation;

		for (int i = 0; i < static_cast<int>(mIndex); ++i)
		{
			int value = mWorkTime[i];
			sum += value;
			sumSquareX += value * value;
		}

		average = sum / static_cast<float>(mIndex);
		averageSquareX = sumSquareX / static_cast<float>(mIndex);

		sDeviation = averageSquareX - average * average;

		sDeviation = sqrtf(sDeviation);

		return sDeviation;
	}

	const std::string& TimeSheet::GetName() const
	{
		return mName;
	}
}
