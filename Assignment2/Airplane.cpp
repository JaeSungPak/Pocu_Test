#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"

#include <iostream>

namespace assignment2
{
	Airplane::Airplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
		SetTravelAndRestTime(eTravelInfo::AIRPLANE_TRAVEL, eRestInfo::AIRPLANE_REST);
	}

	Airplane::~Airplane()
	{
	}

	unsigned int Airplane::GetMaxSpeed() const
	{
		return GetDriveSpeed() > GetFlySpeed() ? GetDriveSpeed() : GetFlySpeed();
	}

	unsigned int Airplane::GetFlySpeed() const
	{
		double index = 200 * exp((800 - static_cast<double>(GetPassengersWeight())) / 500);

		return static_cast<int>(index + 0.5f);
	}

	unsigned int Airplane::GetDriveSpeed() const
	{
		double index = 4 * exp((400 - static_cast<double>(GetPassengersWeight())) / 70);

		return static_cast<int>(index + 0.5f);
	}

	Boatplane Airplane::operator+(Boat& boat)
	{
		int index = boat.GetMaxPassengersCount() + GetMaxPassengersCount();
		Boatplane* bp = new Boatplane(index);

		index = GetPassengersCount();

		for (int i = 0; i < index; i++)
		{
			bp->AddPassenger(GetPassenger(i));
			mPeople[i] = NULL;
		}

		mCurrentCount = 0;

		index = boat.GetPassengersCount();

		for (int i = 0; i < index; i++)
		{
			bp->AddPassenger(boat.GetPassenger(0));
			boat.mPeople[i] = NULL;
		}

		boat.mCurrentCount = 0;

		return *bp;
	}
}