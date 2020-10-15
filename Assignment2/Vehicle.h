#pragma once

#include "Person.h"

namespace assignment2
{
	enum eTravelInfo
	{
		DEFAULT_TRAVEL = 0,

		AIRPLANE_TRAVEL = 1,
		BOAT_TRAVEL = 2,
		BOATPLANE_TRAVEL = 1,
		MOTORCYCLE_TRAVEL = 5,
		SEDAN_TRAVEL = 5,
		UBOAT_TRAVEL = 2
	};

	enum eRestInfo
	{
		DEFAULT_REST = 0,

		AIRPLANE_REST = 3,
		BOAT_REST = 1,
		BOATPLANE_REST = 3,
		MOTORCYCLE_REST = 1,
		SEDAN_REST = 1,
		TRAILERSEDAN_REST = 2,
		UBOAT_REST = 4
	};

	class Vehicle
	{
	public:
		Vehicle(unsigned int maxPassengersCount);
		Vehicle(const Vehicle& other);
		~Vehicle();

		virtual unsigned int GetMaxSpeed() const = 0;

		bool AddPassenger(const Person* person);
		bool RemovePassenger(unsigned int i);
		const Person* GetPassenger(unsigned int i) const;
		unsigned int GetPassengersCount() const;
		unsigned int GetMaxPassengersCount() const;
		unsigned int GetPassengersWeight() const;

		void SetTravelAndRestTime(eTravelInfo travel, eRestInfo rest);
		unsigned int TravelVehicle();

	protected:
		int mMaxCount;
		int mCurrentCount;

		int mCurrentTravelTime;
		int mCurrentRestTime;
		eTravelInfo mTravelTime;
		eRestInfo mRestTime;

		Person** mPeople;
	};
}