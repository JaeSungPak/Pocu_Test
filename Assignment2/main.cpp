#pragma once

#include "Person.h"
#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"
#include <iostream>

using namespace assignment2;
using namespace std;

int main()
{
	Person* p = new Person("Bob", 85);
	Person* p2 = new Person("James", 75);
	Person* p3 = new Person("Tina", 52);

	Person* p4 = new Person("Peter", 78);
	Person* p5 = new Person("Jane", 48);
	Person* p6 = new Person("Steve", 88);
	
	Airplane a(5);
	a.AddPassenger(p);
	a.AddPassenger(p2);
	a.AddPassenger(p3);

	cout << a.GetPassengersWeight() << endl;

	Boat b(5);
	b.AddPassenger(p4);
	b.AddPassenger(p5);
	b.AddPassenger(p6);

	Boatplane bp = b + a; // Airplane + Boat
	cout << bp.GetPassengersCount() << endl; // 6을 반환
	cout << bp.GetMaxPassengersCount() << endl; // 10을 반환

	cout << a.GetPassengersWeight() << endl;

	cout << a.GetPassengersCount() << endl; // 0을 반환
	cout << b.GetPassengersCount() << endl; // 0을 반환

	cout << bp.GetPassenger(0)->GetName() << endl;
	
	return 0;
}