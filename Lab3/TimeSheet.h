#pragma once
#include <string>

namespace lab3
{
	class TimeSheet
	{
	public:
		TimeSheet(const char* name, unsigned int maxEntries);
		~TimeSheet();
		TimeSheet(const TimeSheet& other);
		TimeSheet& operator=(const TimeSheet& rhs);
		void AddTime(int timeInHours);
		int GetTimeEntry(unsigned int index) const;
		int GetTotalTime() const;
		float GetAverageTime() const;
		float GetStandardDeviation() const;
		const std::string& GetName() const;

	private:
		std::string mName;
		unsigned int mMaxEntries;
		int* mWorkTime;
		unsigned int mNameLength;
		unsigned int mIndex;
	};
}

