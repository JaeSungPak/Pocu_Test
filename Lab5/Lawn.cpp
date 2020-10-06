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
		double result = static_cast<double>(grassType) * GetArea() / 100;

		return static_cast<unsigned int>(result - static_cast<int>(result) == 0 ? result : result + 1);
	}

	unsigned int Lawn::GetMinimumSodRollsCount() const
	{
		double result = static_cast<double>(GetArea()) / ROLLGRASSWIDTH;

		return static_cast<unsigned int>(result - static_cast<int>(result) == 0 ? result : result + 1);
	}
}