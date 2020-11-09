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
		double GetVariance();
		double GetStandardDeviation();
		unsigned int GetCount();

	private:
		std::queue<std::stack<int>> mQueue;
		int mCurrentSize;
		int mMaxStackSize;
	};

	//---------------------------------------------------------

	template<typename T>
	QueueStack<T>::QueueStack(unsigned int maxStackSize)
	{
		
	}

	template<typename T>
	QueueStack<T>::QueueStack(const QueueStack& other)
	{

	}

	template<typename T>
	QueueStack<T>::~QueueStack()
	{


	}

	template<typename T>
	void QueueStack<T>::Enqueue(T number)
	{
	}

	template<typename T>
	T QueueStack<T>::Peek()
	{
		return mQueue.front().top();
	}

	template<typename T>
	T QueueStack<T>::Dequeue()
	{
		return 0;
	}

	template<typename T>
	T QueueStack<T>::GetMax()
	{
		return 0;
	}

	template<typename T>
	T QueueStack<T>::GetMin()
	{
		return 0;
	}

	template<typename T>
	double QueueStack<T>::GetAverage()
	{
		return 0;
	}

	template<typename T>
	T QueueStack<T>::GetSum()
	{
		return 0;
	}

	template<typename T>
	double QueueStack<T>::GetVariance()
	{
		return 0;
	}

	template<typename T>
	double QueueStack<T>::GetStandardDeviation()
	{
		return 0;
	}

	template<typename T>
	unsigned int QueueStack<T>::GetCount()
	{
		return 0;
	}
}