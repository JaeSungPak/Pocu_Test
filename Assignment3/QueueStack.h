#pragma once

#include <queue>
#include <stack>

namespace assignment3
{

	template <typename T>
	class QueueStack
	{
	public:
		QueueStack(unsigned int maxStackSize);
		QueueStack(const QueueStack& other);
		~QueueStack();
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
		int mMaxStackSize;
	};

	//---------------------------------------------------------

	template<typename T>
	QueueStack<T>::QueueStack(unsigned int maxStackSize)
		: mMaxStackSize(maxStackSize)
	{
		mQueue.push({});
	}

	template<typename T>
	QueueStack<T>::QueueStack(const QueueStack& other)
		: mQueue(other.mQueue)
		, mMaxStackSize(other.mMaxStackSize)
	{

	}

	template<typename T>
	QueueStack<T>::~QueueStack()
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
	}

	template<typename T>
	T QueueStack<T>::Peek()
	{
		return mQueue.front().top();
	}

	template<typename T>
	T QueueStack<T>::Dequeue()
	{
		T temp = mQueue.front().top();

		mQueue.front().pop();

		if (mQueue.front().size() == 0)
		{
			mQueue.pop();
		}

		return temp;
	}

	template<typename T>
	T QueueStack<T>::GetMax()
	{
		T temp = std::numeric_limits<T>::min();

		QueueStack<T> clone(*this);

		unsigned int size = clone.GetCount();

		for (unsigned int i = 0; i < size; i++)
		{
			T pop = clone.Dequeue();

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

		QueueStack<T> clone(*this);

		unsigned int size = clone.GetCount();

		for (unsigned int i = 0; i < size; i++)
		{
			T pop = clone.Dequeue();

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
		int sum = 0;

		QueueStack<T> clone(*this);

		unsigned int size = clone.GetCount();

		for (unsigned int i = 0; i < size; i++)
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
		unsigned int count = 0;

		std::queue<std::stack<T>> clone;

		clone = mQueue;

		int size = clone.size();

		for (int i = 0; i < size; i++)
		{
			count += clone.front().size();

			clone.pop();
		}

		return count;
	}

	template<typename T>
	QueueStack<T> QueueStack<T>::operator=(const QueueStack<T>& other)
	{
		if (this != &other) 
		{
			mQueue = other.mQueue;

			mMaxStackSize = other.mMaxStackSize;
		}

		return *this;
	}
}