#include <cassert>
#include "SmartStack.h"
#include "SmartQueue.h"
#include "QueueStack.h"
#include <iostream>

using namespace assignment3;

int main()
{
	const double EPSILON = 0.0009765625;

	SmartStack<float> ss;

	ss.Push(3);

	ss.Push(4);

	ss.Push(5);

	ss.Push(6);

	SmartStack<float> sss;

	sss = ss;

	return 0;

}
