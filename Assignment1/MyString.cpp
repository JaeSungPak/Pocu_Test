#include "MyString.h"
#include <iostream>

#define MAX_LENGTH (256)

namespace assignment1
{
    MyString::MyString(const char* s)
    {
        mString = new char[MAX_LENGTH];
        for (int i = 0; mString[i] = s[i]; i++);
    }

    MyString::MyString(const MyString& other)
    {
        mString = new char[MAX_LENGTH];
        for (int i = 0; mString[i] = other.GetCString()[i]; i++);
    }

    MyString::~MyString()
    {
        delete[] mString;
    }

    unsigned int MyString::GetLength() const
    {
        int length;
        for (length = 0; mString[length] != '\0'; length++);
        return length;
    }

    unsigned int MyString::GetLength(const char* string) const
    {
        int length;
        for (length = 0; string[length] != '\0'; length++);
        return length;
    }

    const char* MyString::GetCString() const
    {
        return mString;
    }

    void MyString::Append(const char* s)
    {
        int length = GetLength();
        int i = 0;

        for (int i = 0; mString[length] = s[i]; i++, length++);
    }

    MyString MyString::operator+(const MyString& other) const
    {
        MyString clone(*this);

        clone.Append(other.GetCString());

        return clone;
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
        char temp[MAX_LENGTH];

        for (int i = 0; temp[i] = mString[i]; i++);

        int thisLength = GetLength();
        int sLength = GetLength(s);
        int tempLocal = 0;
        int sLocal = 0;

        for (int i = 0; i < thisLength + sLength;)
        {
            thisLength > tempLocal ? mString[i++] = temp[tempLocal++] : false;

            sLength > sLocal ? mString[i++] = s[sLocal++] : false;
        }
        
        mString[sLength + thisLength] = '\0';
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