#include <iostream>

#include "TimeSheet.h"

int main()
{
    lab3::TimeSheet employee1("John", 10);
    employee1.AddTime(4);
    employee1.AddTime(7);
    employee1.AddTime(6);
    employee1.AddTime(5);
    employee1.AddTime(1);
    employee1.AddTime(2);
    lab3::TimeSheet employee2("Anna", 2);
    employee2 = employee1;
    std::cout << "Employee: " << employee1.GetName() << " / AverageTime: " << employee1.GetAverageTime() << " / AverageTime: " << employee1.GetAverageTime() << " / TotalTime: " << employee1.GetTotalTime() << std::endl;
    std::cout << "Employee: " << employee2.GetName() << " / AverageTime: " << employee1.GetAverageTime() << " / AverageTime: " << employee2.GetAverageTime() << " / TotalTime: " << employee2.GetTotalTime() << std::endl;
    return 0;
}