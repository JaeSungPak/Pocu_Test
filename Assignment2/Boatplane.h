#pragma once

#include "Vehicle.h"
#include "IDivable.h"
#include "IFlyable.h"
#include "ISailable.h"

namespace assignment2
{
	class Boatplane : Vehicle, IDivable, IFlyable, ISailable
	{
	public:
		Boatplane(unsigned int maxPassengersCount);
		~Boatplane();

		virtual unsigned int GetMaxSpeed() const;
		virtual unsigned int GetFlySpeed() const;
		virtual unsigned int GetDiveSpeed() const;
		virtual unsigned int GetSailSpeed() const;
	};
}