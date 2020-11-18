#pragma once
#include <queue>
#include <memory>

namespace lab9
{
	template <typename T>
	class ObjectPool final
	{

	public:
		ObjectPool() = delete;
		ObjectPool(size_t maxPoolSize);
		~ObjectPool();
		T* Get();
		void Return(T* object);
		size_t GetFreeObjectCount();
		size_t GetMaxFreeObjectCount();

	private:
		std::queue<T*> mObjects;
		size_t mMaxPoolSize;
	};

	template<typename T>
	ObjectPool<T>::ObjectPool(size_t maxPoolSize)
		: mObjects()
		, mMaxPoolSize(maxPoolSize)
	{
	}

	template<typename T>
	ObjectPool<T>::~ObjectPool()
	{
		while (!mObjects.empty())
		{
			delete mObjects.front();

			mObjects.pop();
		}
	}

	template<typename T>
	T* ObjectPool<T>::Get()
	{
		if (mObjects.empty())
		{
			return new T();
		}

		T* temp = mObjects.front();

		mObjects.pop();

		return temp;
	}

	template<typename T>
	void ObjectPool<T>::Return(T* object)
	{
		if (mObjects.size() < mMaxPoolSize)
		{
			mObjects.push(object);
		}
		else
		{
			delete object;
		}
	}

	template<typename T>
	size_t ObjectPool<T>::GetFreeObjectCount()
	{
		return mObjects.size();
	}

	template<typename T>
	size_t ObjectPool<T>::GetMaxFreeObjectCount()
	{
		return mMaxPoolSize;
	}
}