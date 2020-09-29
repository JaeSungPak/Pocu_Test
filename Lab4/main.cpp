#include <cassert>
#include <iostream>

#include "Point.h"
#include "PolyLine.h"

using namespace lab4;

int main()
{

	/* ----------------------- */

	PolyLine pl1;
	

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
	bool bRemoved = pl1.RemovePoint(4);
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