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
			mLine[mLocate] = Point(x, y);

			mLocate += 1;

			return true;
		}

		return false;
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		if (mLocate < 10)
		{
			mLine[mLocate] = *point;

			mLocate += 1;

			return true;
		}

		return false;
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		if (static_cast<signed int>(i) < mLocate)
		{
			for (int j = i; j < mLocate - 1; j++)
			{
				mLine[j] = mLine[j + 1];
			}

			mLocate--;

			return true;
		}

		return false;
	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		return false;
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		return new Point(0.0f, 0.0f);
	}
}