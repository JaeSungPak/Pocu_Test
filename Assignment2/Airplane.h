#pragma once

#include "Boatplane.h"
#include "Vehicle.h"
#include "IDrivable.h"
#include "IFlyable.h"

namespace assignment2
{
	class Boat;

	class Airplane : public Vehicle, public IDrivable, public IFlyable
	{
	public:
		Airplane(unsigned int maxPassengersCount);
		~Airplane();

		virtual unsigned int GetMaxSpeed() const;
		virtual unsigned int GetFlySpeed() const;
		virtual unsigned int GetDriveSpeed() const;

		Boatplane operator+(Boat& boat);

	private:
		friend class Boat;
	};
}