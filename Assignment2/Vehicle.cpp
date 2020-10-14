#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount) 
		: mMaxCount(maxPassengersCount)
		, mCurrentCount(0)
		, mTravelTime(eTravelInfo::DEFAULT_TRAVEL)
		, mRestTime(eRestInfo::DEFAULT_REST)
		, mCurrentTravelTime(0)
		, mCurrentRestTime(0)
	{
		mPeople = new Person* [maxPassengersCount];
	}

	Vehicle::~Vehicle()
	{
		for (int i = 0; i < mCurrentCount; i++)
		{
			delete mPeople[i];
		}
		delete[] mPeople;
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		if (mCurrentCount < mMaxCount && person != nullptr)
		{

			mPeople[mCurrentCount] = person->mPointer;

			mCurrentCount++;

			return true;
		}

		return false;
	}

	bool Vehicle::RemovePassenger(unsigned int i)
	{
		if (mCurrentCount > static_cast<int>(i) && i >= 0)
		{
			for (int index = i; index < mCurrentCount - 1; index++)
			{
				mPeople[i] = mPeople[i + 1];
			}

			mPeople[mCurrentCount - 1] = nullptr;

			mCurrentCount--;

			return true;
		}

		return false;
	}

	unsigned int Vehicle::GetPassengersCount() const
	{
		return mCurrentCount;
	}

	unsigned int Vehicle::GetMaxPassengersCount() const
	{
		return mMaxCount;
	}

	unsigned int Vehicle::GetPassengersWeight() const
	{
		int index = 0;

		for (unsigned int i = 0; i < GetPassengersCount(); i++)
		{
			index += GetPassenger(i)->GetWeight();
		}
		return index;
	}

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		if (mCurrentCount > static_cast<int>(i) && i >= 0)
		{
			return mPeople[i];
		}

		return NULL;
	}

	void Vehicle::SetTravelAndRestTime(eTravelInfo travel, eRestInfo rest)
	{
		mTravelTime = travel;
		
		mRestTime = rest;
	}

	unsigned int Vehicle::TravelVehicle()
	{
		if (mCurrentRestTime == 0)
		{
			mCurrentTravelTime++;

			if (mCurrentTravelTime == mTravelTime)
			{
				mCurrentRestTime = mRestTime;

				mCurrentTravelTime = 0;
			}

			return GetMaxSpeed();
		}

		mCurrentRestTime--;

		return 0;
	}
}