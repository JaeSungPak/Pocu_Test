#include <cstring>
#include <cmath>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine() : mLocate(0)
	{
		mLine = new Point[10];
	}

	PolyLine::PolyLine(const PolyLine& other) : mLocate(other.mLocate)
	{
		mLine = new Point[10];

		for (int i = 0; i < mLocate; i++)
		{
			mLine[i] = other.mLine[i];
		}
	}

	PolyLine::~PolyLine()
	{
		delete[] mLine;
	}

	bool PolyLine::AddPoint(float x, float y)
	{	/*
		if (mLocate < 10)
		{
			mLine[mLocate] = Point(x, y);

			mLocate += 1;

			return true;
		}
		*/
		return false;
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		/*
		if (point = &mLine[mLocate])
		{
			return true;
		}
		

		if (mLocate < 10)
		{
			mLine[mLocate] = *point;

			mLocate += 1;

			return true;
		}
		*/
		return false;
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		return false;
	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		if (mLocate < 1)
		{
			return false;
		}

		float maxX = LONG_MIN;
		float minX = static_cast<float>(LONG_MAX);
		float maxY = LONG_MIN;
		float minY = static_cast<float>(LONG_MAX);

		for (int i = 0; i < mLocate; i++)
		{
			maxX = maxX < mLine[i].GetX() ? mLine[i].GetX() : maxX;
			minX = minX > mLine[i].GetX() ? mLine[i].GetX() : minX;
			maxY = maxY < mLine[i].GetY() ? mLine[i].GetY() : maxY;
			minY = minY > mLine[i].GetY() ? mLine[i].GetY() : minY;
		}

		*outMin = Point(minX, minY);
		*outMax = Point(maxX, maxY);

		return true;
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		
		if (static_cast<signed int>(i) < mLocate)
		{
			return &mLine[i];
		}
		
		return NULL;
	}
}