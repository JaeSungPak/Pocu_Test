#pragma once

#include <memory>
#include <vector>

namespace lab11
{
	template<typename T>
	class Storage
	{
	public:
		Storage(unsigned int length);
		Storage(Storage<T>&& other);
		Storage(const Storage<T>& other);
		Storage(unsigned int length, const T& initialValue);

		bool Update(unsigned int index, const T& data);
		const std::unique_ptr<T[]>& GetData() const;
		unsigned int GetSize() const;
		Storage<T>& operator=(Storage<T>&& other);
		Storage<T>& operator=(const Storage<T>& other);

	private:
		size_t mSize;
		std::unique_ptr<T[]> mArray;
		Storage<T>* mPointer;
	};

	template<typename T>
	Storage<T>::Storage(unsigned int length)
		: mSize(length)
		, mPointer(this)
		, mArray(new T[length] {})
	{

	}

	template<typename T>
	Storage<T>::Storage(Storage<T>&& other)
		: mSize(other.mPointer->mSize)
		, mPointer(this)
		, mArray(std::move(other.mPointer->mArray))
	{
		other.mPointer->mSize = 0;
	}

	template<typename T>
	Storage<T>::Storage(const Storage<T>& other)
		: mSize(other.mPointer->mSize)
		, mPointer(this)
		, mArray(new T[mSize])
	{
		for (unsigned int i = 0; i < mSize; i++)
		{
			mArray[i] = other.mArray[i];
		}
	}

	template<typename T>
	Storage<T>::Storage(unsigned int length, const T& initialValue)
		: mSize(length)
		, mPointer(this)
		, mArray(new T[length])
	{
		for (unsigned int i = 0; i < length; i++)
		{
			mArray[i] = initialValue;
		}
	}


	template<typename T>
	bool Storage<T>::Update(unsigned int index, const T& data)
	{
		if (index < mSize && mArray != nullptr)
		{
			mArray[index] = data;

			return true;
		}

		return false;
	}

	template<typename T>
	const std::unique_ptr<T[]>& Storage<T>::GetData() const
	{
		return mArray;
	}

	template<typename T>
	unsigned int Storage<T>::GetSize() const
	{
		return mSize;
	}

	template<typename T>
	Storage<T>& Storage<T>::operator=(Storage<T>&& other)
	{
		if (&other != this)
		{
			mArray = std::move(other.mPointer->mArray);

			mSize = other.mPointer->mSize;

			other.mPointer->mSize = 0;
		}

		return *this;
	}

	template<typename T>
	Storage<T>& Storage<T>::operator=(const Storage<T>& other)
	{
		if (&other != this)
		{
			mSize = other.mPointer->mSize;

			mArray.reset(new T[mSize]);

			for (unsigned int i = 0; i < mSize; i++)
			{
				mArray[i] = other.mArray[i];
			}
		}

		return *this;
	}
	
}