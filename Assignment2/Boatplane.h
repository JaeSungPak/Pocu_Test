#pragma once

#include "Vehicle.h"
#include "IDrivable.h"
#include "IFlyable.h"
#include "ISailable.h"

namespace assignment2
{
	class Boatplane : public Vehicle, public IFlyable, public ISailable
	{
	public:
		Boatplane(unsigned int maxPassengersCount);
		virtual ~Boatplane();

		virtual unsigned int GetMaxSpeed() const;
		virtual unsigned int GetFlySpeed() const;
		virtual unsigned int GetSailSpeed() const;

		Boatplane* operator= (const Boatplane& other);
	};
}