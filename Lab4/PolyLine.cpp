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
	{
		if (mLocate < 10)
		{
			delete &mLine[mLocate];

			mLine[mLocate] = *new Point(x, y);

			mLocate += 1;

			return true;
		}

		return false;
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		return false;
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		return false;
	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		return false;
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		if (static_cast<signed int>(i) < mLocate && static_cast<signed int>(i) >= 0)
		{
			return &mLine[i];
		}

		return NULL;
	}
}