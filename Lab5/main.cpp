#include <iostream>

#include "RectangleLawn.h"
#include "CircleLawn.h"
#include "EquilateralTriangleLawn.h"

using namespace std;
using namespace lab5;

int main()
{
	EquilateralTriangleLawn* a = new EquilateralTriangleLawn(5);

	cout << a->GetArea() << endl;

	return 0;
}