#include <vector>
#include <iostream>
#include "Lap6.h"

int main()
{
	std::vector<int> v;
	v.push_back(4);
	v.push_back(3);
	v.push_back(4);
	v.push_back(12);
	v.push_back(7);
	v.push_back(11);

	std::cout << lab6::NumberWithMaxOccurrence(v);

	return 0;
}