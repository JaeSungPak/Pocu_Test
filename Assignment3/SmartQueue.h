#pragma once

#include <queue>
#include <limits>

namespace assignment3
{
	template <typename T>
	class SmartQueue final
	{

	public:
		SmartQueue() = default;
		SmartQueue(const SmartQueue& other);
		~SmartQueue() = default;

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
		SmartQueue operator=(const SmartQueue& other);

	private:
		std::queue<T> mQueue;
		T mMaxT;
		T mMinT;


	};

	//---------------------------------------------------------

	template<typename T>
	SmartQueue<T>::SmartQueue(const SmartQueue& other)
		: mQueue(other.mQueue)
		, mMaxT(std::numeric_limits<T>::lowest())
		, mMinT(std::numeric_limits<T>::max())
	{

	}

	template<typename T>
	void SmartQueue<T>::Enqueue(T number)
	{
		mQueue.push(number);
	}

	template<typename T>
	T SmartQueue<T>::Peek()
	{
		return mQueue.front();
	}

	template<typename T>
	T SmartQueue<T>::Dequeue()
	{
		T temp = mQueue.front();

		mQueue.pop();

		return temp;
	}

	template<typename T>
	T SmartQueue<T>::GetMax()
	{
		std::queue<T> clone(mQueue);

		T temp = std::numeric_limits<T>::lowest();

		while (!clone.empty())
		{
			T pop = clone.front();

			clone.pop();

			if (temp < pop)
			{
				temp = pop;
			}
		}

		return temp;
	}

	template<typename T>
	T SmartQueue<T>::GetMin()
	{
		std::queue<T> clone(mQueue);

		T temp = std::numeric_limits<T>::max();

		while (!clone.empty())
		{
			T pop = clone.front();

			clone.pop();

			if (temp > pop)
			{
				temp = pop;
			}
		}

		return temp;
	}

	template<typename T>
	double SmartQueue<T>::GetAverage()
	{
		if (mQueue.empty())
		{
			return 0.0;
		}

		T sum = GetSum();

		return static_cast<double>(sum) / mQueue.size();
	}

	template<typename T>
	T SmartQueue<T>::GetSum()
	{
		std::queue<T> clone(mQueue);

		T sum = 0;

		while (!clone.empty())
		{
			sum += clone.front();

			clone.pop();
		}

		return sum;
	}

	template<typename T>
	double SmartQueue<T>::GetVariance()
	{
		if (mQueue.empty())
		{
			return 0.0;
		}

		double temp = 0;

		double average = GetAverage();

		std::queue<T> clone(mQueue);

		while (!clone.empty())
		{
			temp += pow(clone.front() - average, 2);

			clone.pop();
		}

		return temp / static_cast<double>(mQueue.size());
	}

	template<typename T>
	double SmartQueue<T>::GetStandardDeviation()
	{
		if (mQueue.empty())
		{
			return 0.0;
		}

		return sqrt(GetVariance());
	}

	template<typename T>
	unsigned int SmartQueue<T>::GetCount()
	{
		return mQueue.size();
	}

	template<typename T>
	SmartQueue<T> SmartQueue<T>::operator=(const SmartQueue<T>& other)
	{
		if (this != &other) 
		{
			mQueue = other.mQueue;
		}

		return *this;
	}
}