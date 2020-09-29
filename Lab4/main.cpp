#include <cassert>
#include <iostream>

#include "Point.h"
#include "PolyLine.h"

using namespace lab4;

int main()
{
	Point p1(2.f, 3.f);
	Point p2(-1.f, 4.f);

	Point p3 = p1 + p2;

	assert(p3.GetX() == 1.f);
	assert(p3.GetY() == 7.f);

	Point p4 = p2 - p1;

	assert(p4.GetX() == -3.f);
	assert(p4.GetY() == 1.f);

	float dotProduct = p1.Dot(p2);

	assert(dotProduct == 10.f);

	Point p5 = p1 * 5.f;

	assert(p5.GetX() == 10.f);
	assert(p5.GetY() == 15.f);

	Point p6 = 2.f * p2;

	assert(p6.GetX() == -2.f);
	assert(p6.GetY() == 8.f);

	/* ----------------------- */

	PolyLine pl1;
	bool bRemoved = pl1.RemovePoint(4);

	//assert(bRemoved);

	Point minP(0.f, 0.f);
	Point maxP(0.f, 0.f);

	pl1.TryGetMinBoundingRectangle(&minP, &maxP);

	std::cout << pl1.AddPoint(1.4f, 2.7f) << std::endl;
	std::cout << pl1.AddPoint(1.4f, 2.7f) << std::endl;
	std::cout << pl1.AddPoint(1.4f, 2.7f) << std::endl;
	std::cout << pl1.AddPoint(1.4f, 2.7f) << std::endl;
	std::cout << pl1.AddPoint(1.4f, 2.7f) << std::endl;
	std::cout << pl1.AddPoint(1.4f, 2.7f) << std::endl;
	std::cout << pl1.AddPoint(1.4f, 2.7f) << std::endl;
	std::cout << pl1.AddPoint(1.4f, 2.7f) << std::endl;
	std::cout << pl1.AddPoint(1.4f, 2.7f) << std::endl;
	std::cout << pl1.AddPoint(1.4f, 2.7f) << std::endl;
	std::cout << pl1.AddPoint(1.4f, 2.7f) << std::endl;
	std::cout << pl1.AddPoint(1.4f, 2.7f) << std::endl;

	std::cout << pl1[1]->GetX() << " " << pl1[1]->GetY() << std::endl;
	std::cout << pl1[2]->GetX() << " " << pl1[2]->GetY() << std::endl;
	std::cout << pl1[3]->GetX() << " " << pl1[3]->GetY() << std::endl;
	std::cout << pl1[4]->GetX() << " " << pl1[4]->GetY() << std::endl;
	std::cout << pl1[5]->GetX() << " " << pl1[5]->GetY() << std::endl;
	std::cout << pl1[6]->GetX() << " " << pl1[6]->GetY() << std::endl;


	return 0;
}