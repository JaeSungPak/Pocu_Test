#include "Boatplane.h"

#include <iostream>

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
		SetTravelAndRestTime(eTravelInfo::BOATPLANE_TRAVEL, eRestInfo::BOATPLANE_REST);
	}

	Boatplane::Boatplane(const Boatplane& other)
		:Vehicle(other)
	{
		if (other.IsOperated)
		{
			RemoveAllPassenger();

			mPeople = new Person * [mMaxCount + 1];

			for (int i = 0; i < mMaxCount; i++)
			{
				mPeople[i] = NULL;
			}

			for (int i = 0; i < mCurrentCount; i++)
			{
				mPeople[i] = other.mPeople[i]->mPointer;
			}
		}
	}

	unsigned int Boatplane::GetMaxSpeed() const
	{
		return GetFlySpeed() > GetSailSpeed() ? GetFlySpeed() : GetSailSpeed();
	}

	unsigned int Boatplane::GetFlySpeed() const
	{
		double index = static_cast <double>(150) * exp((-static_cast<double>(GetPassengersWeight()) + 500) / 300);

		return static_cast<int>(index + 0.5f);
	}

	unsigned int Boatplane::GetSailSpeed() const
	{
		double index = (static_cast<double>(800) - static_cast<double>(GetPassengersWeight()) * 1.7f > 20) ? static_cast < double>(800) - static_cast<double>(GetPassengersWeight()) * 1.7f : 20;

		return static_cast<int>(index + 0.5f);
	}

	Boatplane::~Boatplane()
	{
	}
}