#include <cassert>
#include "SmartStack.h"
#include "SmartQueue.h"
#include "QueueStack.h"
#include <iostream>

using namespace assignment3;

int main()
{
	const double EPSILON = 0.0009765625;

	QueueStack<float> ss(3);

	ss.Enqueue(3);

	ss.Enqueue(4);

	ss.Enqueue(5);

	ss.Enqueue(6);

	std::cout << ss.GetAverage() << std::endl;

	return 0;

}
