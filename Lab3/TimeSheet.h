#pragma once

#include <string>

using namespace std;

namespace lab3
{
	class TimeSheet
	{
	public:
		TimeSheet();
		TimeSheet(const char* name, unsigned int maxEntries);
		TimeSheet(const TimeSheet& other);
		void AddTime(int timeInHours);
		int GetTimeEntry(unsigned int index) const;
		int GetTotalTime() const;
		float GetAverageTime() const;
		float GetStandardDeviation() const;
		const std::string& GetName() const;
		const int GetLocate() const;
		~TimeSheet();
		TimeSheet& operator= (const TimeSheet& other);
		int* GetTime() const;

	private:
		std::string mName;
		int* mTime;
		int mTimeLocate;
		int mSize;
	};

}
