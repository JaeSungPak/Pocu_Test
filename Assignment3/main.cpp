#include <cassert>
#include "SmartStack.h"
#include "SmartQueue.h"
#include <iostream>
using namespace assignment3;

int main()
{
    SmartQueue<int> q;
    q.Enqueue(6);
    q.Enqueue(5);
    q.Enqueue(-2); // [ 6, 5, -2 ]

    double variance = q.GetStandardDeviation(); // 12.667

    std::cout << variance << std::endl;

    return 0;

}
