#include "TimeSheet.h"
#include <iostream>

namespace lab3
{
	TimeSheet::TimeSheet() : mTimeLocate(0), mName("")
	{
		mTime = NULL;
	}
	TimeSheet::TimeSheet(const char* name, unsigned int maxEntries) : mTimeLocate(0), mName(name)
	{
		mTime = new int[maxEntries];
	}
	TimeSheet::TimeSheet(const TimeSheet& other)
	{

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

		if (index <= static_cast<unsigned int>(mTimeLocate) && index >= 0)
		{
			return mTime[index];
		}

		return -1;
	}

	int TimeSheet::GetTotalTime() const
	{
		return 0;
	}

	float TimeSheet::GetAverageTime() const
	{
		return 0;
	}
	float TimeSheet::GetStandardDeviation() const
	{
		return 0;
	}
	const std::string& TimeSheet::GetName() const
	{
		return mName;
	}

	const int TimeSheet::GetLocate() const
	{
		return mTimeLocate;
	}

	int* TimeSheet::GetTime() const
	{
		return mTime;
	}
	
	TimeSheet::~TimeSheet()
	{
		//delete[] mTime;
	}
	TimeSheet& TimeSheet::operator= (const TimeSheet& other)
	{
		return *this;
	}

}
