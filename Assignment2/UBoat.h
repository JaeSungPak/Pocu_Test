#pragma once
#include "IDivable.h"
#include "ISailable.h"
#include "Vehicle.h"

namespace assignment2
{
	class UBoat : public Vehicle, public IDivable, public ISailable
	{
	public:
		UBoat();
		~UBoat();

		virtual unsigned int GetMaxSpeed() const;
		virtual unsigned int GetSailSpeed() const;
		virtual unsigned int GetDiveSpeed() const;
	};
}