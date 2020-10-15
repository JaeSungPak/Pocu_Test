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
		return GetFlySpeed() > GetSailSpeed() ? GetFlySpeed() : GetSailSpeed();
	}

	unsigned int Boatplane::GetFlySpeed() const
	{
		double index = 150 * exp((-static_cast<double>((GetPassengersWeight())) + 500) / 300);

		return static_cast<int>(index + 0.5f);
	}

	unsigned int Boatplane::GetSailSpeed() const
	{
		double index = (800 - static_cast<double>(GetPassengersWeight()) * 1.7f > 20) ? 800 - static_cast<double>(GetPassengersWeight()) * 1.7f + 0.5f : 20;

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