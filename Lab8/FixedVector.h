#pragma once

namespace lab8
{
	template <typename T, size_t N>
	class FixedVector final
	{

	public:
		FixedVector();
		~FixedVector() = default;
		bool Add(const T& t);
		bool Remove(const T& t);
		const T& Get(unsigned int index);
		T& operator[](unsigned int index);
		int GetIndex(const T& t);
		const size_t& GetSize() const;
		size_t GetCapacity();

	private:
		size_t mSize;
		T mArray[N];
	};

	//------------------------------

	template <typename T, size_t N>
	FixedVector<T, N>::FixedVector()
		: mSize(0)
	{
		T mArray[N];
	}

	template <typename T, size_t N>
	bool FixedVector<T, N>::Add(const T& t)
	{
		if (mSize < N)
		{
			mArray[mSize] = t;

			mSize++;

			return true;
		}

		return false;
	}

	template <typename T, size_t N>
	bool FixedVector<T, N>::Remove(const T& t)
	{
		int location = GetIndex(t);

		if (location == -1)
		{
			return false;
		}

		for (size_t i = static_cast<size_t>(location); i < mSize; i++)
		{
			mArray[i] = mArray[i + 1];
		}

		mSize--;

		return true;
	}

	template <typename T, size_t N>
	const T& FixedVector<T, N>::Get(unsigned int index)
	{
		return mArray[index];
	}

	template <typename T, size_t N>
	T& FixedVector<T, N>::operator[](unsigned int index)
	{
		return mArray[index];
	}

	template <typename T, size_t N>
	int FixedVector<T, N>::GetIndex(const T& t)
	{
		for (size_t i = 0; i < mSize; i++)
		{
			if (mArray[i] == t)
			{
				return i;
			}
		}

		return -1;
	}

	template <typename T, size_t N>
	const size_t& FixedVector<T, N>::GetSize() const
	{
		return mSize;
	}

	template <typename T, size_t N>
	size_t FixedVector<T, N>::GetCapacity()
	{
		return N;
	}
}