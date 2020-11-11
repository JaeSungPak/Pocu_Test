#pragma once

#include <stack>
#include <limits>

namespace assignment3
{
	template <typename T>
	class SmartStack
	{

	public:
		SmartStack();
		SmartStack(const SmartStack& other);
		~SmartStack();

		void Push(T number);
		T Pop();
		T Peek();
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		double GetVariance();
		double GetStandardDeviation();
		unsigned int GetCount();
		SmartStack operator=(const SmartStack& other);

	private:
		std::stack<T> mStack;
		

	};

	//---------------------------------------------------------

	template<typename T>
	SmartStack<T>::SmartStack()
	{

	}

	template<typename T>
	SmartStack<T>::SmartStack(const SmartStack& other)
		: mStack(other.mStack)
	{
		
	}

	template<typename T>
	SmartStack<T>::~SmartStack()
	{

	}

	template<typename T>
	void SmartStack<T>::Push(T number) 
	{
		mStack.push(number);
	}

	template<typename T>
	T SmartStack<T>::Pop()
	{
		T temp = mStack.top();

		mStack.pop();

		return temp;
	}

	template<typename T>
	T SmartStack<T>::Peek()
	{
		return mStack.top();
	}

	template<typename T>
	T SmartStack<T>::GetMax()
	{
		std::stack<T> clone(mStack);

		T temp = std::numeric_limits<T>::min();

		unsigned int size = mStack.size();

		for (unsigned int i = 0; i < size; i++)
		{
			T pop = clone.top();

			clone.pop();

			if (temp < pop)
			{
				temp = pop;
			}
		}

		return temp;
	}

	template<typename T>
	T SmartStack<T>::GetMin()
	{
		std::stack<T> clone(mStack);

		T temp = std::numeric_limits<T>::max();

		unsigned int size = mStack.size();

		for (unsigned int i = 0; i < size; i++)
		{
			T pop = clone.top();

			clone.pop();

			if (temp > pop)
			{
				temp = pop;
			}
		}

		return temp;
	}

	template<typename T>
	double SmartStack<T>::GetAverage()
	{
		T sum = GetSum();

		return static_cast<double>(sum) / mStack.size();
	}

	template<typename T>
	T SmartStack<T>::GetSum()
	{
		SmartStack clone(*this);

		T sum = 0;

		unsigned int size = mStack.size();

		for (unsigned int i = 0; i < size; i++)
		{
			sum += clone.Pop();
		}

		return sum;
	}

	template<typename T>
	double SmartStack<T>::GetVariance()
	{
		double temp = 0;

		double average = GetAverage();

		SmartStack clone(*this);

		unsigned int size = mStack.size();

		for (unsigned int i = 0; i < size; i++)
		{
			double deviation = clone.Pop() - average;

			temp += pow(deviation, 2);
		}

		return temp / size;
	}

	template<typename T>
	double SmartStack<T>::GetStandardDeviation()
	{
		return sqrt(GetVariance());
	}

	template<typename T>
	unsigned int SmartStack<T>::GetCount()
	{
		return mStack.size();
	}

	template<typename T>
	SmartStack<T> SmartStack<T>::operator=(const SmartStack<T>& other)
	{
		if (this != &other) 
		{
			mStack = other.mStack;
		}
		return *this;
	}
}