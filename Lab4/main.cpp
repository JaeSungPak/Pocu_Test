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

	return 0;
}