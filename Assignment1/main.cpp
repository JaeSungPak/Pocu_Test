#include "MyString.h"
#include <iostream>
#include <string>
#include <cassert>


using namespace assignment1;
using namespace std;


int main()
{
	
	MyString s10("Hello");
	s10.PadRight(8);  // "Hello"
	cout << s10.GetCString() << "a" << endl;
	


	return 0;
	// ���⿡ �ߴ����� �����ؼ� b ���� ���캸�ų�
	// �Ʒ��� ���� assert() �Լ��� �Ẹ����
	// assert(s == s2);	// #include <cassert>�� �ʿ�
}