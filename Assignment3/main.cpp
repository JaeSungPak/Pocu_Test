#include <cassert>
#include <cmath>
#include <algorithm>

#include "QueueStack.h"
#include "SmartStack.h"
#include "SmartQueue.h"
#include <iostream>

using namespace assignment3;

int main()
{
    std::vector<int> a;

    std::sort(a.begin(), a.end(), [](int a, int b) -> bool { return a < b; });

    std::find(a.begin(), a.end(), "");

    SmartQueue<int> s;
    s.Enqueue(6);
    s.Enqueue(5);
    s.Enqueue(-2); // [ 6, 5, -2 ]

    s.Dequeue();
    s.Dequeue();
    s.Dequeue();

    s.Enqueue(6);
    s.Enqueue(5);
    s.Enqueue(-2);

    double variance = s.GetVariance(); // 12.667

    std::cout << s.GetMax() << std::endl;
    std::cout << variance << std::endl;

    return 0;


    

}