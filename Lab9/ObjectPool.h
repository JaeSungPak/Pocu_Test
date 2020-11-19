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
		std::unique_ptr<T>& Get();
		void Return(std::unique_ptr<T>& object);
		size_t GetFreeObjectCount();
		size_t GetMaxFreeObjectCount();

	private:
		std::queue<std::unique_ptr<T>> mObjects;
		size_t mMaxPoolSize;
	};

	template<typename T>
	ObjectPool<T>::ObjectPool(size_t maxPoolSize)
		: mObjects()
		, mMaxPoolSize(maxPoolSize)
	{
	}

	template<typename T>
	std::unique_ptr<T>& ObjectPool<T>::Get()
	{
		if (mObjects.empty())
		{
			return std::make_unique<T>(new T());
		}

		std::unique_ptr<T> temp = std::move(mObjects.front());

		mObjects.pop();

		return std::move(temp);
	}

	template<typename T>
	void ObjectPool<T>::Return(std::unique_ptr<T>& object)
	{
		if (mObjects.size() < mMaxPoolSize)
		{
			mObjects.push(object);
		}
		else
		{
			object.reset();
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