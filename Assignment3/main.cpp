#include <cassert>
#include <cmath>

#include "QueueStack.h"
#include "SmartStack.h"
#include <iostream>

using namespace assignment3;

int main()
{
    SmartStack<int> s;
    s.Push(6);
    s.Push(5);
    s.Push(-2); // [ 6, 5, -2 ]

    double variance = s.GetVariance(); // 12.667

    std::cout << variance << std::endl;

    return 0;

}