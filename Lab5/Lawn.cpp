#include "Lawn.h"

namespace lab5
{
	Lawn::Lawn()
	{
	}

	Lawn::~Lawn()
	{
	}

	unsigned int Lawn::GetGrassPrice(eGrassType grassType) const
	{
		return grassType * GetArea() / 100;
	}

	unsigned int Lawn::GetMinimumSodRollsCount() const
	{
		double result = static_cast<double>(GetArea()) / ROLLGRASSWIDTH;

		return result - static_cast<int>(result) == 0 ? result : result + 1;
	}
}