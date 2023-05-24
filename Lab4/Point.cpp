#include "Point.h"

namespace lab4
{
	Point::Point(float x, float y)
		: mX(x)
		, mY(y)
	{
	}

	Point::~Point()
	{
	}

	Point Point::operator+(const Point& other) const
	{
		return Point(mX + other.GetX(), mY + other.GetY());
	}

	Point Point::operator-(const Point& other) const
	{
		return Point(mX - other.GetX(), mY - other.GetY());
	}

	float Point::Dot(const Point& other) const
	{
		return (mX * other.GetX()) + (mY * other.GetY());
	}

	Point Point::operator*(float operand) const
	{
		return Point(mX * operand, mY * operand);
	}

	Point operator*(float operand, Point& p)
	{
		return Point(p.GetX() * operand, p.GetY() * operand);
	}

	float Point::GetX() const
	{
		return mX;
	}

	float Point::GetY() const
	{
		return mY;
	}
}
