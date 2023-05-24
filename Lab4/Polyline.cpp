#include <cstring>
#include <cmath>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine()
		: mPointCount(0)
		, mPointerCount(0)
		, mPointers(0)
	{
		memset(mPoints, 0, sizeof(mPoints));
	}
	
	
	PolyLine::~PolyLine()
	{
		for (unsigned int i = 0; i < mPointerCount; ++i)
		{
			delete mPointers[i];
			mPointers[i] = nullptr;
		}
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		if (mPointCount == 10)
		{
			return false;
		}

		Point p(x, y);

		mPoints[mPointCount++] = p;

		return true;
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		if (mPointCount == 10)
		{
			return false;
		}
		
		mPoints[mPointCount++] = *point;

		mPointers = new const Point*;

		mPointers[mPointerCount++] = point;

		return true;
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		if (i >= mPointCount)
		{
			return false;
		}
		
		for (unsigned int idx = i; idx < mPointCount - 1; ++idx)
		{
			mPoints[idx] = mPoints[idx + 1];
		}

		return true;
	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		if (mPointCount == 0)
		{
			return false;
		}

		float minX = mPoints[0].GetX();
		float minY = mPoints[0].GetY();
		float maxX = minX;
		float maxY = minY;

		for (unsigned int i = 1; i < mPointCount; ++i)
		{
			float tempX = mPoints[i].GetX();
			float tempY = mPoints[i].GetY();

			if (tempX < minX)
			{
				minX = tempX;
			}
			if (tempY < minY)
			{
				minY = tempY;
			}
			if (tempX > maxX)
			{
				maxX = tempX;
			}
			if (tempY > maxY)
			{
				maxY = tempY;
			}
		}

		Point min(minX, minY);
		Point max(maxX, maxY);

		*outMin = min;
		*outMax = max;

		return true;
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		return &mPoints[i];
	}
}
