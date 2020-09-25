#include "MyString.h"

namespace assignment1
{
    MyString::MyString(const char* s)
    {
        mString = new char[];
    }

    MyString::MyString(const MyString& other)
    {
    }

    MyString::~MyString()
    {
    }

    unsigned int MyString::GetLength() const
    {
        int length;
        for (length = 0; mString[length]; length++);
        return length;
    }

    unsigned int MyString::GetLength(const char* string) const
    {
        int length;
        for (length = 0; string[length]; length++);
        return length;
    }

    const char* MyString::GetCString() const
    {
        return 0;
    }

    void MyString::Append(const char* s)
    {
    }

    MyString MyString::operator+(const MyString& other) const
    {
        return MyString("temporary");
    }

    int MyString::IndexOf(const char* s)
    {
        return 0;
    }

    int MyString::LastIndexOf(const char* s)
    {
        return 0;
    }

    void MyString::Interleave(const char* s)
    {
    }

    bool MyString::RemoveAt(unsigned int index)
    {
        return false;
    }

    void MyString::PadLeft(unsigned int totalLength)
    {
    }

    void MyString::PadLeft(unsigned int totalLength, const char c)
    {
    }

    void MyString::PadRight(unsigned int totalLength)
    {
    }

    void MyString::PadRight(unsigned int totalLength, const char c)
    {
    }

    void MyString::Reverse()
    {
    }

    bool MyString::operator==(const MyString& rhs) const
    {
        return false;
    }

    MyString& MyString::operator=(const MyString& rhs)
    {
        return *this;
    }

    void MyString::ToLower()
    {
    }

    void MyString::ToUpper()
    {
    }
}