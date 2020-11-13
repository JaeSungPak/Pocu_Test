#pragma once

#include <queue>
#include <stack>

namespace assignment3
{
	template <typename T>
	class QueueStack final
	{
	public:
		QueueStack() = delete;
		QueueStack(unsigned int maxStackSize);
		QueueStack(const QueueStack& other);
		~QueueStack() = default;
		void Enqueue(T number);
		T Dequeue();
		T Peek();
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		unsigned int GetCount();
		unsigned int GetStackCount();
		QueueStack operator=(const QueueStack& other);

	private:
		std::queue<std::stack<T>> mQueue;
		unsigned int mMaxStackSize;
		unsigned int mCurrentSize;
	};

	//---------------------------------------------------------

	template<typename T>
	QueueStack<T>::QueueStack(unsigned int maxStackSize)
		: mMaxStackSize(maxStackSize)
		, mCurrentSize(0)
	{
		mQueue.push({});
	}

	template<typename T>
	QueueStack<T>::QueueStack(const QueueStack& other)
		: mQueue(other.mQueue)
		, mMaxStackSize(other.mMaxStackSize)
		, mCurrentSize(other.mCurrentSize)
	{

	}

	template<typename T>
	void QueueStack<T>::Enqueue(T number)
	{
		
		if (mQueue.back().size() >= mMaxStackSize)
		{
			mQueue.push({});
		}

		mQueue.back().push(number);

		mCurrentSize++;
		
	}

	template<typename T>
	T QueueStack<T>::Peek()
	{
		return mQueue.front().top();
	}

	template<typename T>
	T QueueStack<T>::Dequeue()
	{
		std::stack<T>& clone = mQueue.front();

		T temp = clone.top();

		clone.pop();

		if (clone.empty())
		{
			mQueue.pop();
		}

		mCurrentSize--;
		
		return temp;
	}

	template<typename T>
	T QueueStack<T>::GetMax()
	{
		
		T temp = std::numeric_limits<T>::lowest();

		std::queue<std::stack<T>> clone(mQueue);

		while (!clone.empty())
		{
			T pop = clone.front().top();

			if (clone.front().empty())
			{
				clone.pop();
			}

			if (pop > temp)
			{
				temp = pop;
			}
		}
		
		return temp;
	}

	template<typename T>
	T QueueStack<T>::GetMin()
	{
		
		T temp = std::numeric_limits<T>::max();

		std::queue<std::stack<T>> clone(mQueue);

		while (!clone.mQueue.empty())
		{
			T pop = clone.front().top();

			if (clone.front().empty())
			{
				clone.pop();
			}

			if (pop < temp)
			{
				temp = pop;
			}
		}
		
		return temp;
	}

	template<typename T>
	double QueueStack<T>::GetAverage()
	{
		return static_cast<double>(GetSum()) / GetCount();
	}

	template<typename T>
	T QueueStack<T>::GetSum()
	{
		
		T sum = 0;

		QueueStack<T> clone(*this);

		while (!clone.mQueue.empty())
		{
			sum += clone.Dequeue();
		}
		
		return sum;
	}


	template<typename T>
	unsigned int QueueStack<T>::GetStackCount()
	{
		return mQueue.size();
	}

	template<typename T>
	unsigned int QueueStack<T>::GetCount()
	{
		return mCurrentSize;
	}

	template<typename T>
	QueueStack<T> QueueStack<T>::operator=(const QueueStack<T>& other)
	{
		
		if (this != &other) 
		{
			mQueue = other.mQueue;

			mMaxStackSize = other.mMaxStackSize;

			mCurrentSize = other.mCurrentSize;
		}
		
		return *this;
	}
}