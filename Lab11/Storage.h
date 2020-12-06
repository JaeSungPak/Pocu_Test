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
		Storage(const Storage<T>& other);
		Storage(unsigned int length, const T& initialValue);

		bool Update(unsigned int index, const T& data);
		const std::unique_ptr<T[]>& GetData() const;
		unsigned int GetSize() const;
		Storage<T>* operator=(const Storage<T>& other);

	private:
		std::unique_ptr<T[]> mArray;
		size_t mSize;
		Storage<T>* mPointer;
	};

	template<typename T>
	Storage<T>::Storage(unsigned int length)
		: mSize(length)
		, mPointer(this)
		, mArray(new T[length])
	{

		for (int i = 0; i < length; i++)
		{
			mArray[i] = static_cast<T>(0);
		}
	}

	template<typename T>
	Storage<T>::Storage(const Storage<T>& other)
		:mSize(other.mSize)
		, mPointer(this)
		, mArray(std::move(other.mPointer->mArray))
	{
		other.mPointer->mSize = 0;
	}


	template<typename T>
	Storage<T>::Storage(unsigned int length, const T& initialValue)
		: mSize(length)
		, mPointer(this)
		, mArray(new T[length])
	{
		for (int i = 0; i < length; i++)
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
		return std::move(mArray);
	}

	template<typename T>
	unsigned int Storage<T>::GetSize() const
	{
		return mSize;
	}
	
	template<typename T>
	Storage<T>* Storage<T>::operator=(const Storage<T>& other)
	{
		mArray.reset(std::move(other.mArray));

		mSize = other.mSize;

		other.mPointer->mSize = 0;

		return this;
	}
	
}