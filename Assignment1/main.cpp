#include "MyString.h"
#include <iostream>
using namespace assignment1;

int main()
{
	MyString s("hello");
	MyString s2(s);

	s.Interleave(" Worldsfasfas");

	std::cout << s.GetLength() << " " << s.GetCString() << std::endl << (s + s2).GetLength() << " " << (s + s2).GetCString();

	return 0;
	// ���⿡ �ߴ����� �����ؼ� b ���� ���캸�ų�
	// �Ʒ��� ���� assert() �Լ��� �Ẹ����
	// assert(s == s2);	// #include <cassert>�� �ʿ�
}