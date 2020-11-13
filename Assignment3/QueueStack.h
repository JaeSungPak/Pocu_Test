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
		std::stack<T>* mFrontStack;
	};

	//---------------------------------------------------------

	template<typename T>
	QueueStack<T>::QueueStack(unsigned int maxStackSize)
		: mMaxStackSize(maxStackSize)
		, mCurrentSize(0)
	{
		mQueue.push({});

		mFrontStack = &mQueue.front();
	}

	template<typename T>
	QueueStack<T>::QueueStack(const QueueStack& other)
		: mQueue(other.mQueue)
		, mMaxStackSize(other.mMaxStackSize)
		, mCurrentSize(other.mCurrentSize)
		, mFrontStack(&mQueue.front())
	{

	}

	template<typename T>
	void QueueStack<T>::Enqueue(T number)
	{
		if (mQueue.empty())
		{
			mQueue.push({});

			mFrontStack = &mQueue.front();
		}

		mQueue.back().push(number);

		if (mQueue.back().size() >= mMaxStackSize)
		{
			mQueue.push({});
		}

		mCurrentSize++;
		
	}

	template<typename T>
	T QueueStack<T>::Peek()
	{
		return mFrontStack->top();
	}

	template<typename T>
	T QueueStack<T>::Dequeue()
	{
		T temp = mFrontStack->top();

		mFrontStack->pop();

		if (mFrontStack->empty())
		{
			mQueue.pop();

			if (!mQueue.empty())
			{
				mFrontStack = &mQueue.front();
			}
		}

		mCurrentSize--;
		
		return temp;
	}

	template<typename T>
	T QueueStack<T>::GetMax()
	{
		/*
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
		*/
		return 0;// temp;
	}

	template<typename T>
	T QueueStack<T>::GetMin()
	{
		/*
		T temp = std::numeric_limits<T>::max();

		std::queue<std::stack<T>> clone(mQueue);

		while (!clone.empty())
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
		*/
		return 0; // temp;
	}

	template<typename T>
	double QueueStack<T>::GetAverage()
	{
		if (GetCount() == 0)
		{
			return 0;
		}

		return static_cast<double>(GetSum()) / GetCount();
	}

	template<typename T>
	T QueueStack<T>::GetSum()
	{
		
		T sum = 0;
		/*
		std::queue<std::stack<T>> clone(mQueue);

		while (!clone.empty())
		{
			std::stack<T>& stackClone = clone.front();

			while (!stackClone.empty())
			{
				sum += stackClone.top();

				stackClone.pop();
			}

			clone.pop();
		}
		*/
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

			mFrontStack = &mQueue.front();
		}
		
		return *this;
	}
}