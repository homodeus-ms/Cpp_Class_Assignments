#pragma once

#define MAX_VEHICLES (10)

namespace assignment2
{
	struct MovingData
	{
		unsigned int movingCount[MAX_VEHICLES];
		unsigned int turn[MAX_VEHICLES];
	};
}