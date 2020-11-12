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
		
		T temp = mQueue.front().top();

		mQueue.front().pop();

		if (mQueue.front().size() == 0)
		{
			mQueue.pop();
		}

		mCurrentSize--;
		
		return temp;
	}

	template<typename T>
	T QueueStack<T>::GetMax()
	{
		/*
		T temp = std::numeric_limits<T>::min();

		QueueStack<T> clone(*this);

		while (!clone.mQueue.empty())
		{
			T pop = clone.Dequeue();

			if (pop > temp)
			{
				temp = pop;
			}
		}
		*/
		return 0; //temp;
	}

	template<typename T>
	T QueueStack<T>::GetMin()
	{
		/*
		T temp = std::numeric_limits<T>::max();

		QueueStack<T> clone(*this);

		while (!clone.mQueue.empty())
		{
			T pop = clone.Dequeue();

			if (pop < temp)
			{
				temp = pop;
			}
		}
		*/
		return 0; //temp;
	}

	template<typename T>
	double QueueStack<T>::GetAverage()
	{
		return 0; //static_cast<double>(GetSum()) / GetCount();
	}

	template<typename T>
	T QueueStack<T>::GetSum()
	{
		/*
		T sum = 0;

		QueueStack<T> clone(*this);

		while (!clone.mQueue.empty())
		{
			sum += clone.Dequeue();
		}
		*/
		return 0; // sum;
	}


	template<typename T>
	unsigned int QueueStack<T>::GetStackCount()
	{
		return 0; //mQueue.size();
	}

	template<typename T>
	unsigned int QueueStack<T>::GetCount()
	{
		return 0; // mCurrentSize;
	}

	template<typename T>
	QueueStack<T> QueueStack<T>::operator=(const QueueStack<T>& other)
	{
		/*
		if (this != &other) 
		{
			mQueue = other.mQueue;

			mMaxStackSize = other.mMaxStackSize;

			mCurrentSize = other.mCurrentSize;
		}
		*/
		return *this;
	}
}