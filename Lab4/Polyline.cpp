#include <cstring>
#include <cmath>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine()
		: mPointCount(0)
	{
		memset(mPoints, 0, sizeof(mPoints));
	}

	PolyLine::~PolyLine()
	{
		for (unsigned int i = 0; i < mPointCount; ++i)
		{
			delete mPoints[i];
			mPoints[i] = nullptr;
		}
	}
	PolyLine::PolyLine(const PolyLine& other)
		: mPointCount(other.mPointCount)
	{
		for (unsigned int i = 0; i < mPointCount; ++i)
		{
			const Point* p = new const Point(*(other.mPoints[i]));
			mPoints[i] = p;
		}
	}
	PolyLine PolyLine::operator=(const PolyLine& other)
	{
		mPointCount = other.mPointCount;
		
		for (unsigned int i = 0; i < mPointCount; ++i)
		{
			const Point* p = new const Point(*(other.mPoints[i]));
			mPoints[i] = p;
		}

		return *this;
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		if (mPointCount == 10)
		{
			return false;
		}

		const Point* p = new const Point(x, y);

		mPoints[mPointCount++] = p;

		return true;
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		if (mPointCount == 10)
		{
			return false;
		}
		
		mPoints[mPointCount++] = point;

		return true;
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		if (i >= mPointCount)
		{
			return false;
		}
		
		delete mPoints[i];

		for (unsigned int idx = i; idx < mPointCount - 1; ++idx)
		{
			mPoints[idx] = mPoints[idx + 1];
		}

		mPoints[--mPointCount] = nullptr;

		return true;
	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		if (mPointCount == 0)
		{
			return false;
		}

		float minX = mPoints[0]->GetX();
		float minY = mPoints[0]->GetY();
		float maxX = minX;
		float maxY = minY;

		for (unsigned int i = 1; i < mPointCount; ++i)
		{
			float tempX = mPoints[i]->GetX();
			float tempY = mPoints[i]->GetY();

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
		if (i >= mPointCount)
		{
			return nullptr;
		}

		return mPoints[i];
	}
}
