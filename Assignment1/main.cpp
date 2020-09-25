#include "MyString.h"
#include <iostream>
using namespace assignment1;

int main()
{
	MyString s("");
	MyString s2(s);

	s2 = s;
	s.Append("abcdefg");
	std::cout << s.GetLength() << ' ' << s.GetCString() << '-'<< std::endl << (s + s2).GetLength() << ' ' << (s + s2).GetCString() << '-' << std::endl;

	int i = s.LastIndexOf("ell"); // i는 1
	int j = s.LastIndexOf("l"); // j는 3
	int z = s.LastIndexOf("This"); // z는 -1
	std::cout << (s == s2) << std::endl;

	return 0;
	// 여기에 중단점을 설정해서 b 값을 살펴보거나
	// 아래와 같이 assert() 함수를 써보세요
	// assert(s == s2);	// #include <cassert>이 필요
}