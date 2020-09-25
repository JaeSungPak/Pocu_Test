#include "MyString.h"
#include <iostream>
using namespace assignment1;

int main()
{
	MyString s("hello");

	std::cout << s.GetLength();

	return 0;
	// 여기에 중단점을 설정해서 b 값을 살펴보거나
	// 아래와 같이 assert() 함수를 써보세요
	// assert(s == s2);	// #include <cassert>이 필요
}