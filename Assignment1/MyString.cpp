#include "MyString.h"
#include <iostream>

#define MAX_LENGTH (46)

namespace assignment1
{
	MyString::MyString(const char* s)
	{
		const int length = GetLength(s);
		mString = new char[length + 1];
		for (int i = 0; mString[i] = s[i]; i++);
	}

	MyString::MyString(const MyString& other)
	{
		const int length = GetLength(other.GetCString());
		mString = new char[length + 1];
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
		if (s == "")
		{
			return;
		}

		int length = GetLength();
		char* temp = new char[length + GetLength(s) + 1];

		for (int i = 0; temp[i] = mString[i]; i++);
		for (int i = 0; temp[length] = s[i]; i++, length++);
		
		Renew(temp);
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
		if (s == "")
		{
			return;
		}
		int thisLength = GetLength();
		int sLength = GetLength(s);

		char* temp = new char[thisLength + sLength + 1];

		int tempLocal = 0;
		int sLocal = 0;

		for (int i = 0; i < thisLength + sLength;)
		{
			thisLength > tempLocal ? temp[i++] = mString[tempLocal++] : false;

			sLength > sLocal ? temp[i++] = s[sLocal++] : false;
		}

		temp[sLength + thisLength] = '\0';

		Renew(temp);
	}

	bool MyString::RemoveAt(unsigned int index)
	{
		unsigned int length = GetLength();

		if (index >= length)
		{
			return false;
		}

		char* temp = new char[GetLength() + 3];

		for (unsigned int i = 0; i < index; i++)
		{
			temp[i] = mString[i];
		}

		for (unsigned int i = index; i < length; i++)
		{
			temp[i] = mString[i + 1];
		}
		
		Renew(temp);

		return true;
	}

	void MyString::PadLeft(unsigned int totalLength)
	{
		PadLeft(totalLength, ' ');
	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
		unsigned int length = GetLength();

		if (totalLength < length)
		{
			return;
		}

		char* temp = new char[GetLength() + totalLength + 1];

		for (int i = length - 1; i >= 0; i--)
		{
			temp[i + totalLength - length] = mString[i];
		}

		for (unsigned int i = 0; i < totalLength - length; i++)
		{
			temp[i] = c;
		}

		temp[totalLength] = '\0';

		Renew(temp);
	}

	void MyString::PadRight(unsigned int totalLength)
	{
		PadRight(totalLength, ' ');
	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
		unsigned int length = GetLength();

		if (totalLength <= length)
		{
			return;
		}

		char* temp = new char[GetLength() + totalLength + 1];

		for (int i = 0; temp[i] = mString[i]; i++);

		for (unsigned int i = length; i < totalLength; i++)
		{
			temp[i] = c;
		}

		temp[totalLength] = '\0';

		Renew(temp);
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
		if (reinterpret_cast<int>(&rhs) == reinterpret_cast<int>(this))
		{
			return *this;
		}

		const int length = GetLength(rhs.GetCString());
		delete[] mString;
		mString = new char[length + 1];
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

	void MyString::Renew(char*& newC)
	{
		delete[] mString;

		const int size = GetLength(newC);
		mString = new char[size + 2];
		for (int i = 0; mString[i] = newC[i]; i++);
		delete[] newC;
	}
}
