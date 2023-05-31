#pragma once

#include "eFenceType.h"

inline unsigned int GetCount(unsigned int mPerimeter)
{
	return mPerimeter * 4;
}

namespace lab5
{
	class IFenceable
	{
	public:
		virtual unsigned int GetMinimumFencesCount() const = 0;
		virtual unsigned int GetFencePrice(eFenceType fenceType) const = 0;
	};
}
