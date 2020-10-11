#include "Motorcycle.h"

namespace assignment2
{
	Motorcycle::Motorcycle()
		: Vehicle(2)
	{
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

		return (-pow(x / 15, 3) + (x * 2) + 400 > 0) ? (-pow(x / 15, 3) + (x * 2) + 400) : 0;
	}
}