#include "TimeSheet.h"

namespace lab3
{
	TimeSheet::TimeSheet() : mTimeLocate(0), mName(""), mSize(0)
	{
		mTime = NULL;
	}
	TimeSheet::TimeSheet(const char* name, unsigned int maxEntries) : mTimeLocate(0), mName(name), mSize(maxEntries)
	{
		mTime = new int[maxEntries];
	}
	TimeSheet::TimeSheet(const TimeSheet& other) : mTimeLocate(other.mTimeLocate), mName(other.mName), mSize(other.mSize)
	{
		mTime = new int[mSize];
		memcpy(mTime, other.mTime, mSize);
	}

	void TimeSheet::AddTime(int timeInHours)
	{
		if (timeInHours >= 1 && timeInHours <= 10 && (mTimeLocate) < mSize)
		{
			mTime[mTimeLocate] = timeInHours;
			mTimeLocate += 1;
		}
	}
	int TimeSheet::GetTimeEntry(unsigned int index) const
	{
		if (index <= static_cast<unsigned int>(mTimeLocate) && index >= 0)
		{
			return mTime[index];
		}

		return -1;
	}


	int TimeSheet::GetTotalTime() const
	{
		int total = 0;

		for (int i = 0; i < mTimeLocate; i++)
		{
			total += mTime[i];
		}

		return total;
	}

	float TimeSheet::GetAverageTime() const
	{
		float average = static_cast<float>(GetTotalTime()) / mTimeLocate;

		return average;
	}
	float TimeSheet::GetStandardDeviation() const
	{
		float average = GetAverageTime();
		float temp = 0;

		for (int i = 0; i < mTimeLocate; i++)
		{
			float minus = static_cast<float>(mTime[i]);
			temp += (minus - average) * (minus - average);
		}

		return static_cast<float>(sqrt(temp / static_cast<float>(mTimeLocate)));
	}
	const std::string& TimeSheet::GetName() const
	{
		return mName;
	}

	TimeSheet::~TimeSheet()
	{
		delete[] mTime;
	}

	TimeSheet& TimeSheet::operator= (const TimeSheet& other)
	{
		if (reinterpret_cast<int>(this) == reinterpret_cast<int>(&other))
		{
			return *this;
		}
		delete[] mTime;

		mTimeLocate = other.mTimeLocate;
		mName = other.mName;
		mSize = other.mSize;

		mTime = new int[mSize];
		memcpy(mTime, other.mTime, mSize);

		return *this;
		return *this;
	}

}
