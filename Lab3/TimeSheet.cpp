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
		mTimeLocate = other.GetLocate();
		mName = other.GetName();

		mTime = new int[_msize(other.GetTime()) / 4];
		memcpy(mTime, other.GetTime(), _msize(other.GetTime()));
	}

	void TimeSheet::AddTime(int timeInHours)
	{

		
	}
	int TimeSheet::GetTimeEntry(unsigned int index) const
	{
		return 0;
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
