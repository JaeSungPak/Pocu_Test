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

	int i = s.LastIndexOf("ell"); // i�� 1
	int j = s.LastIndexOf("l"); // j�� 3
	int z = s.LastIndexOf("This"); // z�� -1
	std::cout << (s == s2) << std::endl;

	return 0;
	// ���⿡ �ߴ����� �����ؼ� b ���� ���캸�ų�
	// �Ʒ��� ���� assert() �Լ��� �Ẹ����
	// assert(s == s2);	// #include <cassert>�� �ʿ�
}