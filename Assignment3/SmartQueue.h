#pragma once

#include <queue>

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
		T& Dequeue();
		T& Peek();
		T& GetMax();
		T& GetMin();
		double GetAverage();
		T& GetSum();
		double GetVariance();
		double GetStandardDeviation();
		unsigned int GetCount();
		SmartQueue operator=(const SmartQueue& other);

	private:
		std::queue<T> mQueue;

	};

	//---------------------------------------------------------

	template<typename T>
	SmartQueue<T>::SmartQueue(const SmartQueue& other)
		: mQueue(other.mQueue)
	{

	}

	template<typename T>
	void SmartQueue<T>::Enqueue(T number)
	{
		mQueue.push(number);
	}

	template<typename T>
	T& SmartQueue<T>::Peek()
	{
		return mQueue.front();
	}

	template<typename T>
	T& SmartQueue<T>::Dequeue()
	{
		T temp = mQueue.front();

		mQueue.pop();

		return temp;
	}

	template<typename T>
	T& SmartQueue<T>::GetMax()
	{
		std::queue<T> clone(mQueue);

		T temp = std::numeric_limits<T>::min();

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
	T& SmartQueue<T>::GetMin()
	{
		std::queue<T> clone(mQueue);

		T temp = std::numeric_limits<T>::max();

		while(!clone.empty())
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
		if (GetCount() == 0)
		{
			return 0;
		}

		T sum = GetSum();

		return static_cast<double>(sum) / mQueue.size();
	}

	template<typename T>
	T& SmartQueue<T>::GetSum()
	{
		SmartQueue clone(*this);

		T sum = 0;

		while (!clone.mQueue.empty())
		{
			sum += clone.Dequeue();
		}

		return sum;
	}

	template<typename T>
	double SmartQueue<T>::GetVariance()
	{
		if (GetCount() == 0)
		{
			return 0;
		}

		double temp = 0;

		double average = GetAverage();

		SmartQueue clone(*this);

		while (!clone.mQueue.empty())
		{
			double deviation = clone.Dequeue() - average;

			temp += pow(deviation, 2);
		}

		return temp / mQueue.size();
	}

	template<typename T>
	double SmartQueue<T>::GetStandardDeviation()
	{
		if (GetCount() == 0)
		{
			return 0;
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