#include "TimeSheet.h"

namespace lab3
{
    TimeSheet::TimeSheet(const char* name, unsigned int maxEntries)
    {
    }

    TimeSheet::TimeSheet()
    {
    }

    TimeSheet::TimeSheet(const TimeSheet& other)
    {
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
        return 0.0f;
    }

    float TimeSheet::GetStandardDeviation() const
    {
        return 0.0f;
    }

    const std::string& TimeSheet::GetName() const
    {
        return "temporary";
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