#pragma once
#include <string>

namespace lab3
{
    class TimeSheet
    {
    public:
        TimeSheet(const char* name, unsigned int maxEntries);
        TimeSheet(const TimeSheet &other);
        void AddTime(int timeInHours);
        int GetTimeEntry(unsigned int index) const;
        int GetTotalTime() const;
        float GetAverageTime() const;
        float GetStandardDeviation() const;
        const std::string& GetName() const;
        ~TimeSheet();
        TimeSheet& operator= (const TimeSheet& other);

    private:
        TimeSheet();
        std::string mName;
        int *mTime;
        int timeLocate;
    };
}