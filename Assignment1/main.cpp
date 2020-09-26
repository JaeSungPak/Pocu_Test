#include "MyString.h"
#include <iostream>
#include <string>
#include <cassert>


using namespace assignment1;
using namespace std;


int main()
{
	assignment1::MyString my1("pope pope");
	std::string s1("pope pope");

	const char* cString = my1.GetCString();
	assignment1::MyString copied(my1);

	std::cout << my1.LastIndexOf("") << endl;
	std::cout << s1.rfind("") << endl;

	// E0, E1
	assert(my1.IndexOf("p") == s1.find("p"));
	assert(my1.LastIndexOf("p") == s1.rfind("p"));

	assert(my1.IndexOf("pop") == s1.find("pop"));
	assert(my1.LastIndexOf("pop") == s1.rfind("pop"));

	assert(my1.IndexOf("popen") == s1.find("popen"));

	assert(my1.LastIndexOf("popen") == s1.rfind("popen"));

	assert(my1.IndexOf("pope pope love") == s1.find("pope pope love"));
	assert(my1.LastIndexOf("pope pope love") == s1.rfind("pope pope love"));

	assert(my1.IndexOf(" pope") == s1.find(" pope"));
	assert(my1.LastIndexOf("pope ") == s1.rfind("pope "));

	// E2, E3
	assert(my1.IndexOf("") == s1.find(""));
	assert(my1.LastIndexOf("") == s1.rfind(""));

	// E4
	assert(my1 == copied);					// value
	assert(my1.GetCString() == cString);

	return 0;
	// 여기에 중단점을 설정해서 b 값을 살펴보거나
	// 아래와 같이 assert() 함수를 써보세요
	// assert(s == s2);	// #include <cassert>이 필요
}