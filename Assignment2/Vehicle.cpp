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

	Vehicle::Vehicle(const Vehicle& other)
		: mMaxCount(other.mMaxCount)
		, mCurrentCount(other.mCurrentCount)
		, mTravelTime(other.mTravelTime)
		, mRestTime(other.mRestTime)
		, mCurrentTravelTime(other.mCurrentTravelTime)
		, mCurrentRestTime(other.mCurrentRestTime)
	{
		mPeople = new Person * [mMaxCount + 1];

		for (int i = 0; i < mCurrentCount; i++)
		{
			mPeople[i] = new Person(*other.mPeople[i]);
		}
	}

	Vehicle::~Vehicle()
	{
		RemoveAllPassenger();
	}

	void Vehicle::RemoveAllPassenger()
	{
		for (int i = 0; i < mCurrentCount; i++)
		{
			delete mPeople[i];
		}

		delete[] mPeople;
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		for (int i = 0; i < mCurrentCount; i++)
		{
			if (person == mPeople[i])
			{
				return false;
			}
		}

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
			delete mPeople[i];

			for (int index = i; index < mCurrentCount - 1; index++)
			{
				mPeople[index] = mPeople[index + 1];
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

	const Vehicle* Vehicle::operator=(const Vehicle& other)
	{
		const Vehicle* thisPointer = this;

		if (&other == thisPointer)
		{
			return this;
		}

		RemoveAllPassenger();

		mMaxCount = other.mMaxCount;
		mCurrentCount = other.mCurrentCount;
		mTravelTime = other.mTravelTime;
		mRestTime = other.mRestTime;
		mCurrentTravelTime = other.mCurrentTravelTime;
		mCurrentRestTime = other.mCurrentRestTime;

		mPeople = new Person * [mMaxCount + 1];

		for (int i = 0; i < mCurrentCount; i++)
		{
			mPeople[i] = new Person(*other.mPeople[i]);
		}

		return this;
	}
}