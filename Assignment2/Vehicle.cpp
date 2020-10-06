#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount) : mMaxCount(maxPassengersCount), mCount(0)
	{
		mPeople[100] = NULL;
	}

	Vehicle::~Vehicle()
	{
		for (int i = 0; i < mMaxCount; i++)
		{
			delete mPeople[i];
		}
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		if (mCount < mMaxCount && person != nullptr){

			mPeople[mCount] = person->mPointer;

			mCount++;

			return true;
		}

		return false;
	}

	bool Vehicle::RemovePassenger(unsigned int i)
	{
		if (mCount > i && i >= 0)
		{
			for (int index = i; index < mCount - 1; index++)
			{
				mPeople[i] = mPeople[i + 1];
			}

			mPeople[mCount] = nullptr;

			mCount--;

			return true;
		}

		return false;
	}

	unsigned int Vehicle::GetPassengersCount() const
	{
		return mCount;
	}

	unsigned int Vehicle::GetMaxPassengersCount() const
	{
		return mMaxCount;
	}

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		if (i < mCount && i >= 0)
		{
			return mPeople[i];
		}

		return NULL;
	}
}