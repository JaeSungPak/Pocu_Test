#pragma once
#include <iostream>

namespace lab8
{
	template <size_t N>
	class FixedVector<bool, N> final
	{

	public:
		FixedVector();
		~FixedVector() = default;
		bool Add(const bool& t);
		bool Remove(const bool& t);
		bool Get(unsigned int index);
		bool operator[](unsigned int& index);
		int GetIndex(const bool& t);
		size_t& GetSize();
		size_t GetCapacity();
		
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

		for (int i = 0; i < N / 32; i++)
		{
			mArray[i] = 0;
		}
	}

	template <size_t N>
	bool FixedVector<bool, N>::Add(const bool& bIndex)
	{
		if (mSize < N)
		{
			if (bIndex)
			{
				mArray[N / 32] |= (1 << mSize - (N / 32) * 32);

				mSize++;
			}
			else
			{
				mArray[N / 32] &= ~(1 << mSize - (N / 32) * 32);

				mSize++;
			}

			return true;
		}

		return false;
	}

	template <size_t N>
	bool FixedVector<bool, N>::Remove(const bool& bIndex)
	{
		int location = GetIndex(bIndex);

		if (location == -1)
		{
			return false;
		}

		int32_t temp1 = static_cast<int32_t>(pow(2, location)) - 1;
		temp1 &= mArray[0];
		int32_t temp2 = mArray[0] >> (location + 1);
		temp2 <<= location;

		mArray[0] = temp1 + temp2;

		mSize--;

		return true;
	}

	template <size_t N>
	bool FixedVector<bool, N>::Get(unsigned int index)
	{
		return (mArray[0] >> index) % 2 == 0 ? false : true;
	}

	template <size_t N>
	bool FixedVector<bool, N>::operator[](unsigned int& index)
	{
		return (mArray[0] >> index) % 2 == 0 ? false : true;
	}

	template <size_t N>
	int FixedVector<bool, N>::GetIndex(const bool& bIndex)
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
	size_t& FixedVector<bool, N>::GetSize()
	{
		return mSize;
	}

	template <size_t N>
	size_t FixedVector<bool, N>::GetCapacity()
	{
		return N;
	}
}