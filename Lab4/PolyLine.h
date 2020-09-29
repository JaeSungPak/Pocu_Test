#pragma once

#include "Point.h"

namespace lab4
{
	class PolyLine
	{
	public:
		PolyLine();
		PolyLine(const PolyLine& other);
		~PolyLine();

		bool AddPoint(float x, float y);
		bool AddPoint(const Point* point);
		bool RemovePoint(unsigned int i);
		bool TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const;

		const Point* operator[](unsigned int i) const;
		const Point* operator=(Point& other) const;

	private:
		Point* mLine;
		int mLocate;
	};
}