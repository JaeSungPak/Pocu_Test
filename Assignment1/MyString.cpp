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

        int this_Length = GetLength();
        int s_Length = GetLength(s);

        int temp_Local = 0;
        int s_Local = 0;

        for (int i = 0; i < this_Length + s_Length;)
        {
            this_Length > temp_Local ? mString[i++] = temp[temp_Local++] : false;

            s_Length > s_Local ? mString[i++] = s[s_Local++] : false;
        }
        
        mString[s_Length + this_Length] = '\0';
    }

    bool MyString::RemoveAt(unsigned int index)
    {
        int length = GetLength();

        if (index > length)
        {
            return false;
        }

        for (int i = index; i < length; i++)
        {
            mString[i] = mString[i + 1];
        }

        mString[length - 1] = NULL;

        return true;
    }

    void MyString::PadLeft(unsigned int totalLength)
    {
        int length = GetLength();

        if (totalLength < length)
        {
            return;
        }

        for (int i = length - 1; i >= 0; i--)
        {
            mString[i + totalLength - length] = mString[i];
        }

        for (int i = 0; i < totalLength - length; i++)
        {
            mString[i] = ' ';
        }

        mString[totalLength] = '\0';
    }

    void MyString::PadLeft(unsigned int totalLength, const char c)
    {
        int length = GetLength();

        if (totalLength < length)
        {
            return;
        }

        for (int i = length - 1; i >= 0; i--)
        {
            mString[i + totalLength - length] = mString[i];
        }

        for (int i = 0; i < totalLength - length; i++)
        {
            mString[i] = c;
        }

        mString[totalLength] = '\0';
    }

    void MyString::PadRight(unsigned int totalLength)
    {
        int length = GetLength();

        for (int i = length; i < totalLength; i++)
        {
            mString[i] = ' ';
        }

        mString[totalLength] = '\0';
    }

    void MyString::PadRight(unsigned int totalLength, const char c)
    {
        int length = GetLength();

        for (int i = length; i < totalLength; i++)
        {
            mString[i] = c;
        }

        mString[totalLength] = '\0';
    }

    void MyString::Reverse()
    {
        int length = GetLength();

        for (int i = 0; i < length / 2; i++)
        {
            char temp = mString[i];
            mString[i] = mString[length - i - 1];
            mString[length - i - 1] = temp;
        }
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
        int length = GetLength();

        for (int i = 0; i < length; i++)
        {
            mString[i] = mString[i] >= 65 && mString[i] <= 90 ? mString[i] + 32 : mString[i];
        }
    }

    void MyString::ToUpper()
    {
        int length = GetLength();

        for (int i = 0; i < length; i++)
        {
            mString[i] = mString[i] >= 97 && mString[i] <= 122 ? mString[i] - 32 : mString[i];
        }
    }
}