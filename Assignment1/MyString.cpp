#include "MyString.h"
#include <iostream>

#define MAX_LENGTH (64)

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
		if (s == "")
		{
			return 0;
		}

		int length = GetLength();
		int sLength = GetLength(s);

		int index = -1;

		for (int i = 0; i < length - sLength + 1; i++)
		{
			for (int j = 0; j < sLength; j++)
			{
				if (mString[i + j] != s[j])
				{
					break;
				}
				index = j == sLength - 1 ? i : -1;
			}
			if (index >= 0)
			{
				break;
			}
		}
		return index;
	}

	int MyString::LastIndexOf(const char* s)
	{
		if (s == "")
		{
			return GetLength();
		}
		int length = GetLength();
		int sLength = GetLength(s);

		int index = -1;

		for (int i = length - 1; i >= 0; i--)
		{
			for (int j = 0; j < sLength; j++)
			{
				if (mString[i + j] != s[j])
				{
					break;
				}
				index = j == sLength - 1 ? i : -1;
			}
			if (index > 0)
			{
				break;
			}
		}
		return index;
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
		unsigned int length = GetLength();

		if (index > length)
		{
			return false;
		}

		for (unsigned int i = index; i < length; i++)
		{
			mString[i] = mString[i + 1];
		}

		mString[length - 1] = NULL;

		return true;
	}

	void MyString::PadLeft(unsigned int totalLength)
	{
		unsigned int length = GetLength();

		if (totalLength < length)
		{
			return;
		}

		for (int i = length - 1; i >= 0; i--)
		{
			mString[i + totalLength - length] = mString[i];
		}

		for (unsigned int i = 0; i < totalLength - length; i++)
		{
			mString[i] = ' ';
		}

		mString[totalLength] = '\0';
	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
		unsigned int length = GetLength();

		if (totalLength < length)
		{
			return;
		}

		for (int i = length - 1; i >= 0; i--)
		{
			mString[i + totalLength - length] = mString[i];
		}

		for (unsigned int i = 0; i < totalLength - length; i++)
		{
			mString[i] = c;
		}

		mString[totalLength] = '\0';
	}

	void MyString::PadRight(unsigned int totalLength)
	{
		int length = GetLength();

		for (unsigned int i = length; i < totalLength; i++)
		{
			mString[i] = ' ';
		}

		mString[totalLength] = '\0';
	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
		int length = GetLength();

		for (unsigned int i = length; i < totalLength; i++)
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
		int length = GetLength();

		if (length == rhs.GetLength())
		{
			for (int i = 0; i < length; i++)
			{
				if (rhs.GetCString()[i] != mString[i])
				{
					return false;;
				}
			}
		}
		else
		{
			return false;
		}

		return true;
	}

	MyString& MyString::operator=(const MyString& rhs)
	{
		for (int i = 0; mString[i] = rhs.GetCString()[i]; i++);

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
