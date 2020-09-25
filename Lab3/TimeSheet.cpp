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
	TimeSheet::~TimeSheet()
	{
		//delete[] mTime;
	}
	TimeSheet& TimeSheet::operator= (const TimeSheet& other)
	{
		return *this;
	}

}
