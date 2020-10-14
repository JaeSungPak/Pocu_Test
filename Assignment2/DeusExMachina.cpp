#include "DeusExMachina.h"
#include <iostream>

namespace assignment2
{
	DeusExMachina* DeusExMachina::GetInstance()
	{
		static DeusExMachina* mInstance;

		if (mInstance == NULL)
		{
			mInstance = new DeusExMachina();
			
			mInstance->mSize = 0;

			mInstance->mVehicle = new Vehicle*[10];

			mInstance->mTravelDistance = new int [10];
		}

		return mInstance;
	}

	void DeusExMachina::Travel() const
	{
		for (int i = 0; i < mSize; i++)
		{
			mTravelDistance[i] += mVehicle[i]->TravelVehicle();
		}
	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{
		if (mSize < 10 && vehicle != nullptr)
		{
			mVehicle[mSize] = vehicle;

			mTravelDistance[mSize] = 0;

			mSize++;

			return true;
		}

		return false;
	}

	bool DeusExMachina::RemoveVehicle(unsigned int i)
	{
		if (static_cast<int>(i) < mSize && i >= 0)
		{
			for (int index = i; index < mSize - 1; index++)
			{
				mVehicle[index] = mVehicle[index + 1];

				mTravelDistance[index] = mTravelDistance[index + 1];
			}

			mVehicle[mSize - 1] = nullptr;
			
			mSize--;

			return true;
		}

		return false;
	}

	Vehicle* DeusExMachina::GetVehicle(unsigned int i) const
	{
		if (mSize > static_cast<int>(i))
		{
			return mVehicle[i];
		}

		return 0;
	}

	const Vehicle* DeusExMachina::GetFurthestTravelled() const
	{
		int max = 0;

		for (int i = 0; i < mSize; i++)
		{
			max = mTravelDistance[i] > mTravelDistance[max] ? i : max;
		}

		for (int i = 0; i < mSize; i++)
		{
			std::cout << mTravelDistance[i] << " : " << typeid(*mVehicle[i]).name() << std::endl;
		}

		return mVehicle[max];
	}
}