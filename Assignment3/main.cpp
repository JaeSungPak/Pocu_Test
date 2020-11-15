#include <cassert>
#include <cmath>

#include "QueueStack.h"
#include "SmartStack.h"
#include "SmartQueue.h"
#include <iostream>

using namespace assignment3;

int main()
{
    SmartQueue<int> s;
    s.Enqueue(6);
    s.Enqueue(5);
    s.Enqueue(-2); // [ 6, 5, -2 ]

    double variance = s.GetVariance(); // 12.667

    std::cout << s.GetMax() << std::endl;
    std::cout << variance << std::endl;

    return 0;

}