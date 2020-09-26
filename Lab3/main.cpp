#include <iostream>

#include "TimeSheet.h"

int main()
{
    lab3::TimeSheet employee1("", 10);
    
    employee1 = employee1;
    std::cout << "Employee: " << employee1.GetName() << " / AverageTime: " << employee1.GetAverageTime() << " / StandardDeviation: " << employee1.GetStandardDeviation() << " / TotalTime: " << employee1.GetTotalTime() << std::endl;
    //std::cout << "Employee: " << employee2.GetName() << " / AverageTime: " << employee2.GetAverageTime() << " / StandardDeviation: " << employee2.GetStandardDeviation() << " / TotalTime: " << employee2.GetTotalTime() << std::endl;
    return 0;
}