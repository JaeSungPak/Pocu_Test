#pragma once

#include "Vehicle.h"
#include "IDrivable.h"
#include "IFlyable.h"
#include "ISailable.h"

namespace assignment2
{
	class Boatplane : public Vehicle, public IDrivable, public IFlyable, public ISailable
	{
	public:
		Boatplane(unsigned int maxPassengersCount);
		~Boatplane();

		virtual unsigned int GetMaxSpeed() const;
		virtual unsigned int GetFlySpeed() const;
		virtual unsigned int GetDriveSpeed() const;
		virtual unsigned int GetSailSpeed() const;

		Boatplane* operator= (Boatplane other);
	};
}