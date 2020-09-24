#include <iostream>

#include "TimeSheet.h"

int main()
{
    lab3::TimeSheet employee1("", 10);
    employee1.AddTime(4);
    employee1.AddTime(7);
    employee1.AddTime(6);
    employee1.AddTime(5);
    employee1.AddTime(1);
    employee1.AddTime(0);
    lab3::TimeSheet employee2;
    employee1 = employee1;
    //std::cout << "Employee: " << employee1.GetName() << " / AverageTime: " << employee1.GetAverageTime() << " / StandardDeviation: " << employee1.GetStandardDeviation() << " / TotalTime: " << employee1.GetTotalTime() << std::endl;
    //std::cout << "Employee: " << employee2.GetName() << " / AverageTime: " << employee2.GetAverageTime() << " / StandardDeviation: " << employee2.GetStandardDeviation() << " / TotalTime: " << employee2.GetTotalTime() << std::endl;
    return 0;
}