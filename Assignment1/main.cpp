#include "MyString.h"
#include <iostream>
using namespace assignment1;

int main()
{
	MyString s("hello");

	std::cout << s.GetLength();

	return 0;
	// ���⿡ �ߴ����� �����ؼ� b ���� ���캸�ų�
	// �Ʒ��� ���� assert() �Լ��� �Ẹ����
	// assert(s == s2);	// #include <cassert>�� �ʿ�
}