#include "TimeSheet.h"

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
		
		if (timeInHours >= 1 && timeInHours <= 10 && static_cast<unsigned>(mTimeLocate) < _msize(mTime) / 4)
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
