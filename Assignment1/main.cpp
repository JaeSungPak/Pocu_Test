#include "MyString.h"
#include <iostream>
using namespace assignment1;

int main()
{
	MyString s("aBcDeF");
	MyString s2(s);

	s.ToUpper();
	std::cout << s.GetLength() << ' ' << s.GetCString() << std::endl << (s + s2).GetLength() << ' ' << (s + s2).GetCString() << std::endl;
	std::cout << 'A' + 32 << std::endl;

	return 0;
	// ���⿡ �ߴ����� �����ؼ� b ���� ���캸�ų�
	// �Ʒ��� ���� assert() �Լ��� �Ẹ����
	// assert(s == s2);	// #include <cassert>�� �ʿ�
}