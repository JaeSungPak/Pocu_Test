#include "Boatplane.h"

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
		SetTravelAndRestTime(eTravelInfo::BOATPLANE_TRAVEL, eRestInfo::BOATPLANE_REST);
	}

	unsigned int Boatplane::GetMaxSpeed() const
	{
		unsigned int index = GetDriveSpeed() > GetFlySpeed() ? GetDriveSpeed() : GetFlySpeed();

		return index > GetSailSpeed() ? index : GetSailSpeed();
	}

	unsigned int Boatplane::GetFlySpeed() const
	{
		double index = 200 * exp((-(static_cast<double>(GetPassengersWeight())) + 800) / 500);

		return static_cast<int>(index + 0.5f);
	}

	unsigned int Boatplane::GetDriveSpeed() const
	{
		double index = 4 * exp((-(static_cast<double>(GetPassengersWeight())) + 400) / 70);

		return static_cast<int>(index + 0.5f);
	}

	unsigned int Boatplane::GetSailSpeed() const
	{
		double index = (800 - GetPassengersWeight() > 20) ? 800 - GetPassengersWeight() : 20;

		return static_cast<int>(index + 0.5f);
	}

	Boatplane* Boatplane::operator=(Boatplane other)
	{
		mMaxCount = other.GetMaxPassengersCount();
		mCurrentCount = other.GetPassengersCount();

		for (int i = 0; i < mCurrentCount; i++)
		{
			delete mPeople[i];
		}

		delete mPeople;

		mPeople = new Person * [mMaxCount + 1];

		for (int i = 0; i < mCurrentCount; i++)
		{
			mPeople[i] = other.mPeople[i];
		}

		return this;
	}

	Boatplane::~Boatplane()
	{
	}
}