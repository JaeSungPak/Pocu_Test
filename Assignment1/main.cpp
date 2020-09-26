#include "MyString.h"
#include <iostream>
#include <string>
#include <cassert>

using namespace assignment1;
using namespace std;


int main()
{
	
	MyString s10("Hello");
	MyString s1(" World");
	cout << (s10 + s1).GetCString() << s10.GetCString() << "a" << endl;
	
	return 0;
	// 여기에 중단점을 설정해서 b 값을 살펴보거나
	// 아래와 같이 assert() 함수를 써보세요
	// assert(s == s2);	// #include <cassert>이 필요
}