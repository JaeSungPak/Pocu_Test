#pragma once

#include "Boatplane.h"
#include "Vehicle.h"
#include "ISailable.h"

namespace assignment2
{
	class Airplane;

	class Boat : public Vehicle, public ISailable
	{
	public:
		Boat(unsigned int maxPassengersCount);
		~Boat();

		virtual unsigned int GetMaxSpeed() const;
		virtual unsigned int GetSailSpeed() const;

		Boatplane operator+(Airplane& plane);

	private:
		friend class Airplane;
	};
}