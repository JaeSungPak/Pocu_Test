#pragma once

#include <stack>
#include <limits>

namespace assignment3
{
	template <typename T>
	class SmartStack final
	{

	public:
		SmartStack();
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
		T mMaxT;
		T mMinT;
	};

	//---------------------------------------------------------

	template<typename T>
	SmartStack<T>::SmartStack()
		: mMaxT(std::numeric_limits<T>::lowest())
		, mMinT(std::numeric_limits<T>::max())
	{
	}

	template<typename T>
	SmartStack<T>::SmartStack(const SmartStack& other)
		: mStack(other.mStack)
		, mMaxT(other.mMaxT)
		, mMinT(other.mMinT)
	{
		
	}

	template<typename T>
	void SmartStack<T>::Push(T number) 
	{
		if (mMaxT < number)
		{
			mMaxT = number;
		}

		if (mMinT > number)
		{
			mMinT = number;
		}

		mStack.push(number);
	}

	template<typename T>
	T SmartStack<T>::Pop()
	{
		T temp = mStack.top();

		if (temp >= mMaxT)
		{
			mMaxT = std::numeric_limits<T>::lowest();
		}

		if (temp <= mMinT)
		{
			mMinT = std::numeric_limits<T>::max();
		}

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
		if (mMaxT > std::numeric_limits<T>::lowest())
		{
			return mMaxT;
		}

		std::stack<T> clone(mStack);

		while (clone.empty() == false)
		{
			T pop = clone.top();

			clone.pop();

			if (mMaxT < pop)
			{
				mMaxT = pop;
			}
		}

		return mMaxT;
	}

	template<typename T>
	T SmartStack<T>::GetMin()
	{
		if (mMinT < std::numeric_limits<T>::max())
		{
			return mMinT;
		}

		std::stack<T> clone(mStack);

		while (!clone.empty())
		{
			T pop = clone.top();

			clone.pop();

			if (mMinT > pop)
			{
				mMinT = pop;
			}
		}

		return mMinT;
	}

	template<typename T>
	double SmartStack<T>::GetAverage()
	{
		if (mStack.empty())
		{
			return 0.0;
		}

		T sum = GetSum();

		return static_cast<double>(sum) / mStack.size();
	}

	template<typename T>
	T SmartStack<T>::GetSum()
	{
		std::stack<T> clone(mStack);

		T sum = 0;

		while (!clone.empty())
		{
			sum += clone.top();

			clone.pop();
		}

		return sum;
	}

	template<typename T>
	double SmartStack<T>::GetVariance()
	{
		double variance = 0;

		double average = GetAverage();

		double size = static_cast<double>(clone.size());

		std::stack<T> clone(mStack);

		while (!clone.empty())
		{
			T temp = clone.top();

			variance += temp * temp;

			clone.pop();
		}

		variance /= size;

		return variance - average * average;
	}

	template<typename T>
	double SmartStack<T>::GetStandardDeviation()
	{
		if (GetCount() == 0)
		{
			return 0.0;
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