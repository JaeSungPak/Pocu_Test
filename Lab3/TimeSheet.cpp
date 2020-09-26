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

	}
	int TimeSheet::GetTimeEntry(unsigned int index) const
	{
		return -1;
	}


	int TimeSheet::GetTotalTime() const
	{
		return 0;
	}

	float TimeSheet::GetAverageTime() const
	{
		return 0.0f;
	}
	float TimeSheet::GetStandardDeviation() const
	{
		return 0.0f;
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
		delete[] mTime;
	}

	TimeSheet& TimeSheet::operator= (const TimeSheet& other)
	{
		return *this;
	}

}
