#include "Boatplane.h"

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	unsigned int Boatplane::GetMaxSpeed() const
	{
		unsigned int index = GetDiveSpeed() > GetFlySpeed() ? GetDiveSpeed() : GetFlySpeed();

		return index > GetSailSpeed() ? index : GetSailSpeed();
	}

	unsigned int Boatplane::GetFlySpeed() const
	{
		double index = 200 * exp((-(static_cast<int>(GetPassengersCount())) + 800) / 500);

		return static_cast<int>(index);
	}

	unsigned int Boatplane::GetDiveSpeed() const
	{
		double index = 4 * exp((-(static_cast<int>(GetPassengersCount())) + 400) / 70);

		return static_cast<int>(index);
	}

	unsigned int Boatplane::GetSailSpeed() const
	{
		double index = (800 - GetPassengersCount() > 20) ? 800 - GetPassengersCount() : 20;

		return static_cast<int>(index);
	}

	Boatplane::~Boatplane()
	{
	}
}