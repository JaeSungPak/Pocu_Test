#include "MyString.h"
#include <iostream>
#include <string>
#include <cassert>
#include <iomanip>
#include <string>

using namespace assignment1;
using namespace std;

class Animal
{
public:
	Animal(const char* name) : mName(name)
	{

	}
	~Animal()
	{
		delete mName;
	}

	virtual void PrintName() const = 0;

protected:
	const char* mName;
};

class Cat : public Animal
{
public:
	Cat(const char* name) : Animal(name)
	{

	}
	~Cat()
	{

	}
	void PrintName() const
	{
		std::cout << mName << std::endl;
	}
};


int main()
{
	
	Cat* a = new Cat("Kitty");
	Cat b(*a);
	//delete a;
	b.PrintName();

	return 0;
	// ���⿡ �ߴ����� �����ؼ� b ���� ���캸�ų�
	// �Ʒ��� ���� assert() �Լ��� �Ẹ����
	// assert(s == s2);	// #include <cassert>�� �ʿ�
}