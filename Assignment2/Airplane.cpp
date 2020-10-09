#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"

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
		return GetDiveSpeed() > GetFlySpeed() ? GetDiveSpeed() : GetFlySpeed();
	}

	unsigned int Airplane::GetFlySpeed() const
	{
		double index = 200 * exp((-(static_cast<int>(GetPassengersCount())) + 800) / 500);

		return static_cast<int>(index);
	}

	unsigned int Airplane::GetDiveSpeed() const
	{
		double index = 4 * exp((-(static_cast<int>(GetPassengersCount())) + 400) / 70);

		return static_cast<int>(index);
	}

	Boatplane Airplane::operator+(Boat& boat)
	{
		Boatplane* instance;


		Boatplane bp(0);
		return bp;
	}
}