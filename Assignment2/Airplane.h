#pragma once

#include "Boatplane.h"
#include "Vehicle.h"
#include "IDivable.h"
#include "IFlyable.h"

namespace assignment2
{
	class Boat;

	class Airplane : public Vehicle, public IDivable, public IFlyable
	{
	public:
		Airplane(unsigned int maxPassengersCount);
		~Airplane();

		virtual unsigned int GetMaxSpeed() const;
		virtual unsigned int GetFlySpeed() const;
		virtual unsigned int GetDiveSpeed() const;

		Boatplane operator+(Boat& boat);
	};
}