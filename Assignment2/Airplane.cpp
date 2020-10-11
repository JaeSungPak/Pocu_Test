#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"

#include <iostream>

namespace assignment2
{
	Airplane::Airplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
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
		double index = 200 * exp((800 - static_cast<int>(GetPassengersWeight())) / 500);

		return static_cast<int>(index);
	}

	unsigned int Airplane::GetDriveSpeed() const
	{
		double index = 4 * exp((400 - static_cast<int>(GetPassengersWeight())) / 70);

		return static_cast<int>(index);
	}

	Boatplane Airplane::operator+(Boat& boat)
	{
		int index = boat.GetMaxPassengersCount() + GetMaxPassengersCount();
		Boatplane* bp = new Boatplane(index);

		index = GetPassengersCount();

		for (int i = 0; i < index; i++)
		{
			bp->AddPassenger(GetPassenger(0));
			RemovePassenger(0);
		}

		index = boat.GetPassengersCount();

		for (int i = 0; i < index; i++)
		{
			bp->AddPassenger(boat.GetPassenger(0));
			RemovePassenger(0);
		}

		return *bp;
	}
}