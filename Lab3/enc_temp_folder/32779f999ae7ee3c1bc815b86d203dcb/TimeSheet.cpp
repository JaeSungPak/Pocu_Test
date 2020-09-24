#include "TimeSheet.h"

namespace lab3
{
	
	TimeSheet::TimeSheet(const char* name, unsigned int maxEntries) : mTimeLocate(0), mName(name)
	{
		mTime = new int[maxEntries];
	}
	TimeSheet::TimeSheet(const TimeSheet& other) : mTimeLocate(other.mTimeLocate), mName(other.mName)
	{
		mTime = new int[_msize(other.mTime) / sizeof(int)];
		memcpy(mTime, other.mTime, _msize(other.mTime));
	}
	void TimeSheet::AddTime(int timeInHours)
	{
		if (timeInHours >= 1 && timeInHours <= 10 && static_cast<unsigned>(mTimeLocate) < _msize(mTime) / sizeof(int))
		{ 
			mTime[mTimeLocate] = timeInHours;
			mTimeLocate += 1;
		}
	}
	int TimeSheet::GetTimeEntry(unsigned int index) const
	{
		if (index <= (unsigned int)mTimeLocate && index >= 0)
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
			temp += pow(mTime[i] - average, 2);
		}
		return sqrt(temp / mTimeLocate);
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
		mTimeLocate = other.mTimeLocate;
		mName = other.mName;
		delete[] mTime;
		mTime = new int[_msize(other.mTime) / sizeof(int)];
		memcpy(mTime, other.mTime, _msize(other.mTime));

		return *this;
	}

}