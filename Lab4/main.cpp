#include <cassert>
#include <iostream>

#include "Point.h"
#include "PolyLine.h"

using namespace lab4;
using namespace std;

int main()
{
	cout << "- PolyLine::operator[]() -" << endl;
	PolyLine pl;
	pl.AddPoint(1.7f, 2.4f);
	pl.AddPoint(3.9f, 2.1f);
	pl.AddPoint(5.3f, 5.5f);
	pl.AddPoint(-2.1f, 4.0f);

	cout << pl[0]->GetX() << ", " << pl[0]->GetY() << endl;  // [1.7f, 2.4f]
	assert(pl[0]->GetX() == 1.7f && pl[0]->GetY() == 2.4f);
	cout << pl[3]->GetX() << ", " << pl[3]->GetY() << endl;  // [-2.1f, 4.0f]
	assert(pl[3]->GetX() == -2.1f && pl[3]->GetY() == 4.0f);
	assert(pl[6] == nullptr);  // NULL

	PolyLine pl3(pl);
	Point* p2 = new Point(10.1f, 20.1f);
	assert(pl3.AddPoint(p2) == true);
	assert(pl3.AddPoint(50.2f, 25.4f) == true);
	assert(pl3.AddPoint(150.2f, 25.4f) == true);
	assert(pl3.AddPoint(250.2f, 25.4f) == true);
	assert(p2->GetX() == 10.1f && p2->GetY() == 20.1f);
	assert(pl3[0]->GetX() == 1.7f && pl3[0]->GetY() == 2.4f);
	assert(pl3[4]->GetX() == 10.1f && pl3[4]->GetY() == 20.1f);
	assert(pl3[5]->GetX() == 50.2f && pl3[5]->GetY() == 25.4f);
	assert(pl3[10] == nullptr);  // NULL
	assert(pl3[-4] == nullptr);  // NULL
	assert(pl3[20] == nullptr);  // NULL

	PolyLine* pl4 = new PolyLine(pl);
	Point* p3 = new Point(10.1f, 20.1f);
	Point* p4 = new Point(40.1f, 30.1f);
	assert(pl4->AddPoint(p3) == true);
	assert(pl4->AddPoint(50.2f, 25.4f) == true);
	assert(pl4->AddPoint(p4) == true);
	assert((*pl4)[0]->GetX() == 1.7f && (*pl4)[0]->GetY() == 2.4f);
	assert((*pl4)[4]->GetX() == 10.1f && (*pl4)[4]->GetY() == 20.1f);
	assert((*pl4)[5]->GetX() == 50.2f && (*pl4)[5]->GetY() == 25.4f);
	assert((*pl4)[6]->GetX() == 40.1f && (*pl4)[6]->GetY() == 30.1f);
	assert((*pl4)[7] == nullptr);  // NULL
	assert((*pl4)[10] == nullptr);  // NULL
	assert((*pl4)[-4] == nullptr);  // NULL

	delete pl4;

	cout << "- PolyLine::operator[]() - END -" << endl;


	return 0;
}