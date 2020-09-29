#include <cstring>
#include <cmath>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine() : mLocate(0)
	{
		mLine[10] = NULL;
	}

	PolyLine::PolyLine(const PolyLine& other) : mLocate(other.mLocate)
	{
		mLine[10];

		for (int i = 0; i < mLocate; i++)
		{
			mLine[i] = new Point();
			*mLine[i] = *other[i];
		}
	}

	PolyLine::~PolyLine()
	{
		for (int i = 0; i < mLocate; i++)
		{
			delete mLine[i];
		}
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		if (mLocate < 10)
		{
			mLine[mLocate] = new Point(x, y);

			mLocate += 1;

			return true;
		}

		return false;
	}

	bool PolyLine::AddPoint(Point* point)
	{
		if (mLocate < 10)
		{
			mLine[mLocate] = point;

			mLocate += 1;

			return true;
		}

		return false;
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		if (static_cast<signed int>(i) < mLocate && static_cast<signed int>(i) >= 0)
		{
			delete mLine[i];

			for (int j = i; j < mLocate; j++)
			{
				mLine[j] = mLine[j + 1];
			}

			mLine[mLocate] = nullptr;

			mLocate--;

			return true;
		}

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
			maxX = maxX < mLine[i]->GetX() ? mLine[i]->GetX() : maxX;
			minX = minX > mLine[i]->GetX() ? mLine[i]->GetX() : minX;
			maxY = maxY < mLine[i]->GetY() ? mLine[i]->GetY() : maxY;
			minY = minY > mLine[i]->GetY() ? mLine[i]->GetY() : minY;
		}

		*outMin = Point(minX, minY);
		*outMax = Point(maxX, maxY);

		return true;
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		int j = i;

		if (j < mLocate && j >= 0)
		{
			return mLine[j];
		}
		
		return NULL;
	}

	const PolyLine& PolyLine::operator=(PolyLine other)
	{
		for (int i = 0; i < mLocate; i++)
		{
			delete mLine[i];
		}

		mLocate = other.mLocate;

		for (int i = 0; i < mLocate; i++)
		{
			mLine[i] = new Point();
			*mLine[i] = *other[i];
		}

		return *this;
	}
}