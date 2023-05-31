#pragma once

#include "Lawn.h"
#include "IFenceable.h"

#define SQRT3_DIVIDED4 (0.43301270189221932338186158537647)

namespace lab5
{
	class EquilateralTriangleLawn : public Lawn, public IFenceable
	{
	public:
		EquilateralTriangleLawn(unsigned int length);
		virtual ~EquilateralTriangleLawn();

		unsigned int GetArea() const;

		unsigned int GetMinimumFencesCount() const;
		unsigned int GetFencePrice(eFenceType fenceType) const;

	private:
		unsigned int mSide;
		unsigned int mPerimeter;
		unsigned int mFenceCount;
		
	};
}