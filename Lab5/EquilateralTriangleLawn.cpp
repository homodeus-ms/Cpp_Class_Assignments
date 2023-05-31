#include "EquilateralTriangleLawn.h"

namespace lab5
{
	EquilateralTriangleLawn::EquilateralTriangleLawn(unsigned int length)
		: Lawn()
		, mSide(length)
		, mPerimeter(length * 3)
	{
		mFenceCount = GetCount(mPerimeter);
		mArea = GetArea();
	}
	EquilateralTriangleLawn::~EquilateralTriangleLawn()
	{

	}
	unsigned int EquilateralTriangleLawn::GetArea() const
	{
		return static_cast<unsigned int>((SQRT3_DIVIDED4 * mSide * mSide) + 0.5);
	}
	unsigned int EquilateralTriangleLawn::GetMinimumFencesCount() const
	{
		return mFenceCount;
	}
	unsigned int EquilateralTriangleLawn::GetFencePrice(eFenceType fenceType) const
	{
		return mPerimeter * fenceType;
	}
}