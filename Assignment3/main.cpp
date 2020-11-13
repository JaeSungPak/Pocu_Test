#include <cassert>
#include <cmath>

#include "QueueStack.h"
#include <iostream>

using namespace assignment3;

int main()
{
    QueueStack<double> ss(3);

    ss.Enqueue(3.4);
    ss.Enqueue(1.2);
    ss.Enqueue(4.6);
    ss.Enqueue(3.32);
    ss.Enqueue(10.2);
    ss.Enqueue(1.1);
    ss.Enqueue(-5.9);
    ss.Enqueue(1.1);
    ss.Enqueue(-12.4);
    ss.Enqueue(9.2);

    assert(ss.GetCount() == 10U);
    assert(ss.Peek() == 4.6);
    //assert(ss.GetMax() == 10.2);
    //assert(ss.GetMin() == -12.4);
    std::cout << ss.GetSum() << std::endl;
    //assert(ss.GetSum() == 15.82);
    std::cout << ss.GetAverage() << std::endl;
    //assert(ss.GetAverage() == 1.582);
    //assert(ss.Peek() == 9.2);
    std::cout << ss.Peek() << std::endl;

    double popped1 = ss.Dequeue();
    double popped2 = ss.Dequeue();
    ss.Dequeue();
    ss.Dequeue();
    ss.Dequeue();
    ss.Dequeue();
    ss.Dequeue();
    ss.Dequeue();
    ss.Dequeue();
    ss.Dequeue();

    ss.Enqueue(3.4);

    assert(popped1 == 9.2);
    assert(popped2 == -12.4);

    return 0;

}