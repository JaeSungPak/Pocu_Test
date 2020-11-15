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


    s.Pop();
    s.Pop(); // [ 6, 5, -2 ]
    s.Pop();

    s.Push(6);
    s.Push(5);
    s.Push(-2);


    std::cout << s.GetMax() << std::endl;
    std::cout << s.GetMin() << std::endl;

    return 0;

}