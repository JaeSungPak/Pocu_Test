#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"

namespace assignment2
{
	Boat::Boat(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
		SetTravelAndRestTime(eTravelInfo::BOAT_TRAVEL, eRestInfo::BOAT_REST);
	}

	Boat::~Boat()
	{
	}

	unsigned int Boat::GetMaxSpeed() const
	{
		return GetSailSpeed();
	}
	unsigned int Boat::GetSailSpeed() const
	{
		return 800 - GetPassengersWeight() * 10 > 20 ? 800 - GetPassengersWeight() * 10 : 20;
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		int index = plane.GetMaxPassengersCount() + GetMaxPassengersCount();
		Boatplane* bp = new Boatplane(index);

		index = plane.GetPassengersCount();

		for (int i = 0; i < index; i++)
		{
			bp->AddPassenger(plane.GetPassenger(0));
			plane.RemovePassengerWithoutDelete(0);
		}

		index = GetPassengersCount();

		for (int i = 0; i < index; i++)
		{
			bp->AddPassenger(GetPassenger(0));
			RemovePassengerWithoutDelete(0);
		}

		return *bp;
	}
}