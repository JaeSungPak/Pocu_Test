#include "Motorcycle.h"

namespace assignment2
{
	Motorcycle::Motorcycle()
		: Vehicle(2)
	{
		SetTravelAndRestTime(eTravelInfo::MOTORCYCLE_TRAVEL, eRestInfo::MOTORCYCLE_REST);
	}

	Motorcycle::~Motorcycle()
	{
	}

	unsigned int Motorcycle::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}
	unsigned int Motorcycle::GetDriveSpeed() const
	{
		double x = static_cast<double>(GetPassengersWeight());

		return (-pow(x / 15, 3) + (x * 2) + 400 > 0) ? static_cast<unsigned int>(-pow(x / 15, 3) + (x * 2) + 400 + 0.5f) : 0;
	}
}