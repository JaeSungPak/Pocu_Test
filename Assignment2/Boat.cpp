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
		return (800 - GetPassengersWeight() > 20) ? static_cast<unsigned int>(800 - GetPassengersWeight() + 0.5f) : 20;
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		int index = plane.GetMaxPassengersCount() + GetMaxPassengersCount();
		Boatplane* bp = new Boatplane(index);

		index = GetPassengersCount();

		for (int i = 0; i < index; i++)
		{
			bp->AddPassenger(GetPassenger(0));
			RemovePassenger(0);
		}

		index = plane.GetPassengersCount();

		for (int i = 0; i < index; i++)
		{
			bp->AddPassenger(plane.GetPassenger(0));
			plane.RemovePassenger(0);
		}

		return *bp;
	}
}