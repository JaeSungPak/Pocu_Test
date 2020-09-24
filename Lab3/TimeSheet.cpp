#include "TimeSheet.h"

namespace lab3
{
	
	TimeSheet::TimeSheet(const char* name, unsigned int maxEntries) : timeLocate(0), mName(name)
	{
		mTime = new int[maxEntries];
	}
	TimeSheet::TimeSheet(const TimeSheet& other)
	{
		mTime = new int[_msize(other.mTime) / sizeof(int)];
		memcpy(mTime, other.mTime, _msize(other.mTime));
	}
	void TimeSheet::AddTime(int timeInHours)
	{
		if (timeInHours >= 1 && timeInHours <= 10 && (unsigned)timeLocate < _msize(mTime) / sizeof(int))
		{ 
			mTime[timeLocate] = timeInHours;
			timeLocate += 1;
		}
	}
	int TimeSheet::GetTimeEntry(unsigned int index) const
	{
		if (index <= (unsigned)timeLocate && index >= 0)
		{
			return mTime[index];
		}
		return -1;
	}
	int TimeSheet::GetTotalTime() const
	{
		int total = 0;

		for (int i = 0; i < timeLocate; i++)
		{
			total += mTime[i];
		}
		return total;
	}
	float TimeSheet::GetAverageTime() const
	{
		float average = (float)GetTotalTime() / timeLocate;

		return average;
	}
	float TimeSheet::GetStandardDeviation() const
	{
		float average = GetAverageTime();
		float temp = 0;

		for (int i = 0; i < timeLocate; i++)
		{
			temp += pow(mTime[i] - average, 2);
		}
		return sqrt(temp / timeLocate);
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
		timeLocate = other.timeLocate;
		mName = other.mName;
		delete[] mTime;
		mTime = new int[_msize(other.mTime) / sizeof(int)];
		memcpy(mTime, other.mTime, _msize(other.mTime));

		return *this;
	}

}