#pragma once

#include <stack>

namespace assignment3
{
	template <typename T>
	class SmartStack final
	{

	public:
		SmartStack() = default;
		SmartStack(const SmartStack& other);
		~SmartStack() = default;

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
	SmartStack<T>::SmartStack(const SmartStack& other)
		: mStack(other.mStack)
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

		while(!clone.empty())
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
		while (!clone.empty())
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
		if (GetCount() == 0)
		{
			return 0;
		}

		T sum = GetSum();

		return static_cast<double>(sum) / mStack.size();
	}

	template<typename T>
	T SmartStack<T>::GetSum()
	{
		SmartStack clone(*this);

		T sum = 0;

		while (!clone.mStack.empty())
		{
			sum += clone.Pop();
		}

		return sum;
	}

	template<typename T>
	double SmartStack<T>::GetVariance()
	{
		if (GetCount() == 0)
		{
			return 0;
		}

		double temp = 0;

		double average = GetAverage();

		SmartStack clone(*this);

		while (!clone.mStack.empty())
		{
			double deviation = clone.Pop() - average;

			temp += pow(deviation, 2);
		}

		return temp / mStack.size();
	}

	template<typename T>
	double SmartStack<T>::GetStandardDeviation()
	{
		if (GetCount() == 0)
		{
			return 0;
		}

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