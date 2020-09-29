#include "Point.h"

namespace lab4
{
	Point::Point() : mX(0), mY(0), mPointer(this)
	{
	}

	Point::Point(float x, float y) : mX(x), mY(y), mPointer(this)
	{
	}

	Point::~Point()
	{
	}
	
	Point& Point::operator=(const Point& other)
	{
		mX = other.mX;
		mY = other.mY;
		mPointer = other.mPointer;

		return *this;
	}

	Point Point::GetThis() const
	{
		return *this;
	}

	
	Point Point::operator+(const Point& other) const
	{
		Point point(mX + other.mX, mY + other.mY);

		return point;
	}

	bool Point::operator==(const Point& other) const
	{
		return (mX == other.mX && mY == other.mY) ? true : false;
	}

	Point Point::operator-(const Point& other) const
	{
		Point point(mX - other.mX, mY - other.mY);

		return point;
	}

	float Point::Dot(const Point& other) const
	{
		return (mX * other.mX) + (mY * other.mY);
	}

	void Point::SetPoint(float x, float y)
	{
		mX = x;
		mY = y;
	}

	Point Point::operator*(float operand) const
	{
		Point point(mX * operand, mY * operand);

		return point;
	}

	Point operator*(float operand, const Point& point)
	{
		return point * operand;
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