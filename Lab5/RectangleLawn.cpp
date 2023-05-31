#include "RectangleLawn.h"

namespace lab5
{
	RectangleLawn::RectangleLawn(unsigned int width, unsigned int height)
		: Lawn()
		, mWidth(width)
		, mHeight(height)
		, mPerimeter(2 * (width + height))
	{
		mFenceCount = GetCount(mPerimeter);
		mArea = GetArea();
	}
	RectangleLawn::~RectangleLawn()
	{
	}
	unsigned int RectangleLawn::GetArea() const
	{
		return mWidth * mHeight;
	}
	unsigned int RectangleLawn::GetMinimumFencesCount() const
	{
		return mFenceCount;
	}
	unsigned int RectangleLawn::GetFencePrice(eFenceType fenceType) const
	{
		return mPerimeter * fenceType;
	}
}