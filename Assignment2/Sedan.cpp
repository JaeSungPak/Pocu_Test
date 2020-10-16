#include "Sedan.h"
#include "Trailer.h"

namespace assignment2
{
	Sedan::Sedan()
		: Vehicle(4)
	{
		mTrailer = NULL;

		SetTravelAndRestTime(eTravelInfo::SEDAN_TRAVEL, eRestInfo::SEDAN_REST);
	}

	Sedan::Sedan(const Sedan& other)
		: Vehicle(other)
	{
		mTrailer = new Trailer(*other.mTrailer);
	}

	Sedan::~Sedan()
	{
		if (mTrailer != NULL) {
			delete mTrailer;
		}
	}

	bool Sedan::AddTrailer(const Trailer* trailer)
	{
		if (mTrailer == nullptr)
		{
			mTrailer = trailer->mPointer;

			SetTravelAndRestTime(eTravelInfo::SEDAN_TRAVEL, eRestInfo::TRAILERSEDAN_REST);

			return true;
		}

		return false;
	}

	bool Sedan::RemoveTrailer()
	{
		if (mTrailer != nullptr)
		{
			delete mTrailer;

			SetTravelAndRestTime(eTravelInfo::SEDAN_TRAVEL, eRestInfo::SEDAN_REST);

			mTrailer = nullptr;

			return true;
		}

		return false;
	}

	unsigned int Sedan::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}

	unsigned int Sedan::GetDriveSpeed() const
	{
		unsigned int weight = mTrailer != nullptr ? mTrailer->GetWeight() + GetPassengersWeight() : GetPassengersWeight();
		unsigned int speed;

		if (weight > 350)
		{
			speed = 300;
		}
		else if (weight > 260)
		{
			speed = 380;
		}
		else if (weight > 160)
		{
			speed = 400;
		}
		else if (weight > 80)
		{
			speed = 458;
		}
		else
		{
			speed = 480;
		}

		return speed;
	}

	const Sedan* Sedan::operator=(const Sedan& other)
	{
		Vehicle::operator=(other);

		if (other.mTrailer != NULL)
		{
			if (mTrailer != NULL)
			{
				delete mTrailer;

				mTrailer = NULL;
			}

			mTrailer = new Trailer(*other.mTrailer);
		}

		return this;
	}
}