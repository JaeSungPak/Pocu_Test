#include "TimeSheet.h"
#include <iostream>

namespace lab3
{
	TimeSheet::TimeSheet() : mTimeLocate(0), mName("")
	{
		
	}
	TimeSheet::TimeSheet(const char* name, unsigned int maxEntries) : mTimeLocate(0), mName(name)
	{
		
	}
	TimeSheet::TimeSheet(const TimeSheet& other) : mTimeLocate(other.mTimeLocate), mName(other.mName)
	{
		
	}

	void TimeSheet::AddTime(int timeInHours)
	{

		
	}
	int TimeSheet::GetTimeEntry(unsigned int index) const
	{

		
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
		//delete[] mTime;
	}
	TimeSheet& TimeSheet::operator= (const TimeSheet& other)
	{

		if (reinterpret_cast<int>(this) == reinterpret_cast<int>(&other))
		{
			return *this;
		}
		mTimeLocate = other.mTimeLocate;
		mName = other.mName;
		delete[] mTime;
		mTime = new int[_msize(other.mTime) / 4];
		memcpy(mTime, other.mTime, _msize(other.mTime));

		return *this;
	}

}
