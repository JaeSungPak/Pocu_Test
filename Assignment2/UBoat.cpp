#include "UBoat.h"

namespace assignment2
{
	UBoat::UBoat()
		: Vehicle(50)
	{
		SetTravelAndRestTime(eTravelInfo::UBOAT_TRAVEL, eRestInfo::UBOAT_REST);
	}

	UBoat::~UBoat()
	{
	}

	unsigned int UBoat::GetMaxSpeed() const
	{
		return GetDiveSpeed() > GetSailSpeed() ? GetDiveSpeed() : GetSailSpeed();
	}

	unsigned int UBoat::GetSailSpeed() const
	{
		return (550 - static_cast<double>(GetPassengersWeight()) / 10 > 200) ? (550 - static_cast<double>(GetPassengersWeight()) / 10 + 0.5f) : 200;
	}

	unsigned int UBoat::GetDiveSpeed() const
	{
		return static_cast<unsigned int>(500 * log((GetPassengersWeight() + 150) / 150) + 30 + 0.5f);
	}
}