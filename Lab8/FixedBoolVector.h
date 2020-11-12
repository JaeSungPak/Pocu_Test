#pragma once
#include <iostream>

namespace lab8
{
	template <size_t N>
	class FixedVector<bool, N> final
	{

	public:
		FixedVector();
		FixedVector(FixedVector<bool, N>& other);
		~FixedVector() = default;
		bool Add(const bool t);
		bool Remove(const bool t);
		bool Get(unsigned int index);
		bool operator[](unsigned int index);
		int GetIndex(const bool t);
		size_t GetSize();
		size_t GetCapacity();
		FixedVector<bool, N>& operator= (FixedVector<bool, N>& other);
		
	private:
		size_t mSize;
		int32_t mArray[N / 32 + 1];
	};

	//------------------------------

	template <size_t N>
	FixedVector<bool, N>::FixedVector()
		: mSize(0)
	{
		int32_t mArray[N / 32 + 1];

		for (int i = 0; i < N / 32 + 1; i++)
		{
			mArray[i] = 0;
		}
	}

	template <size_t N>
	FixedVector<bool, N>::FixedVector(FixedVector<bool, N>& other)
		: mSize(other.mSize)
	{
		int32_t mArray[N / 32 + 1];

		for (int i = 0; i < N / 32 + 1; i++)
		{
			mArray[i] = other.mArray[i];
		}
	}

	template <size_t N>
	bool FixedVector<bool, N>::Add(const bool bIndex)
	{
		if (mSize < N)
		{
			if (bIndex)
			{
				mArray[mSize / 32] |= (1 << mSize);

				mSize++;
			}
			else
			{
				mArray[mSize / 32] &= ~(1 << mSize);

				mSize++;
			}

			return true;
		}

		return false;
	}

	template <size_t N>
	bool FixedVector<bool, N>::Remove(const bool bIndex)
	{
		int location = GetIndex(bIndex);

		if (location == -1)
		{
			return false;
		}

		//해당 위치의 정수 조정

		int32_t temp1 = static_cast<int32_t>(pow(2, location % 32)) - 1;
		temp1 &= mArray[location / 32];
		int32_t temp2 = mArray[location / 32] >> (location + 1);
		temp2 <<= location;

		mArray[location / 32] = temp1 + temp2;

		//상위 배열들 하나씩 당기기

		for (int i = location / 32 + 1; i < N / 32 + 1; i++)
		{
			if (Get(i * 32))
			{
				mArray[i - 1] |= (1 << 31);
			}
			else
			{
				mArray[i - 1] &= ~(1 << 31);
			}

			mArray[i] >>= 1;
		}

		mSize--;

		return true;
	}

	template <size_t N>
	bool FixedVector<bool, N>::Get(unsigned int index)
	{
		return (mArray[index / 32] >> index % 32) % 2 == 0 ? false : true;
	}

	template <size_t N>
	bool FixedVector<bool, N>::operator[](unsigned int index)
	{
		return (mArray[index / 32] >> index % 32) % 2 == 0 ? false : true;
	}

	template <size_t N>
	int FixedVector<bool, N>::GetIndex(const bool bIndex)
	{
		for (size_t i = 0; i < mSize; i++)
		{
			if (Get(i) == bIndex)
			{
				return i;
			}
		}

		return -1;
	}

	template <size_t N>
	size_t FixedVector<bool, N>::GetSize()
	{
		return mSize;
	}

	template <size_t N>
	size_t FixedVector<bool, N>::GetCapacity()
	{
		return N;
	}

	template <size_t N>
	FixedVector<bool, N>& FixedVector<bool, N>::operator= (FixedVector<bool, N>& other)
	{
		mSize = other.mSize;

		for (int i = 0; i < N / 32 + 1; i++)
		{
			mArray[i] = other.mArray[i];
		}

		return *this;
	}
}