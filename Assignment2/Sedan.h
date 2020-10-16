#pragma once
#include "Vehicle.h"
#include "IDrivable.h"

namespace assignment2
{
	class Trailer;

	class Sedan : public Vehicle, public IDrivable
	{
	public:
		Sedan();
		Sedan(const Sedan& other);
		~Sedan();

		virtual unsigned int GetMaxSpeed() const;
		virtual unsigned int GetDriveSpeed() const;

		bool AddTrailer(const Trailer* trailer);
		bool RemoveTrailer();
		const Sedan* operator=(const Sedan& other);

		Trailer* mTrailer;
	private:
	};
}