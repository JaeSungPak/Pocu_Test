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
		~ObjectPool() = default;
		T* Get();
		void Return(T* object);
		size_t GetFreeObjectCount();
		size_t GetMaxFreeObjectCount();

	private:
		std::queue<T*> objects;
		size_t mMaxPoolSize;
	};

	template<typename T>
	ObjectPool<T>::ObjectPool(size_t maxPoolSize)
		: objects()
		, mMaxPoolSize(maxPoolSize)
	{
	}

	template<typename T>
	T* ObjectPool<T>::Get()
	{
		if (objects.empty())
		{
			return new T();
		}

		std::unique_ptr<T> a;

		T* temp = objects.front();

		objects.pop();

		return temp;
	}

	template<typename T>
	void ObjectPool<T>::Return(T* object)
	{
		if (objects.size() < mMaxPoolSize)
		{
			objects.push(object);
		}
		else
		{
			delete object;
		}
	}

	template<typename T>
	size_t ObjectPool<T>::GetFreeObjectCount()
	{
		return objects.size();
	}

	template<typename T>
	size_t ObjectPool<T>::GetMaxFreeObjectCount()
	{
		return mMaxPoolSize;
	}
}