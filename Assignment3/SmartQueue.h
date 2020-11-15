#pragma once

#include <queue>
#include <limits>

namespace assignment3
{
	template <typename T>
	class SmartQueue final
	{

	public:
		SmartQueue();
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
	SmartQueue<T>::SmartQueue()
		: mMaxT(std::numeric_limits<T>::lowest())
		, mMinT(std::numeric_limits<T>::max())
	{

	}

	template<typename T>
	SmartQueue<T>::SmartQueue(const SmartQueue& other)
		: mQueue(other.mQueue)
		, mMaxT(other.mMaxT)
		, mMinT(other.mMinT)
	{

	}

	template<typename T>
	void SmartQueue<T>::Enqueue(T number)
	{
		if (mMaxT < number)
		{
			mMaxT = number;
		}

		if (mMinT > number)
		{
			mMinT = number;
		}

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

		if (temp >= mMaxT)
		{
			mMaxT = std::numeric_limits<T>::lowest();
		}

		if (temp <= mMinT)
		{
			mMinT = std::numeric_limits<T>::max();
		}

		mQueue.pop();

		return temp;
	}

	template<typename T>
	T SmartQueue<T>::GetMax()
	{
		if (mMaxT > std::numeric_limits<T>::lowest())
		{
			return mMaxT;
		}

		std::queue<T> clone(mQueue);

		while (!clone.empty())
		{
			T pop = clone.front();

			clone.pop();

			if (mMaxT < pop)
			{
				mMaxT = pop;
			}
		}

		return mMaxT;
	}

	template<typename T>
	T SmartQueue<T>::GetMin()
	{
		if (mMinT < std::numeric_limits<T>::max())
		{
			return mMinT;
		}

		std::queue<T> clone(mQueue);

		while (!clone.empty())
		{
			T pop = clone.front();

			clone.pop();

			if (mMinT > pop)
			{
				mMinT = pop;
			}
		}

		return mMinT;
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
		double variance = 0;

		double sum = 0;

		std::queue<T> clone(mQueue);

		for(int i = 0; i < mQueue.size(); i++)
		{
			double temp = static_cast<double>(clone.front());

			sum += temp / static_cast<double>(clone.size());

			variance += temp * temp / static_cast<double>(clone.size());

			clone.pop();
		}

		return variance - sum * sum;
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