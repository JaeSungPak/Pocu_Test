#pragma once

#include "eGrassType.h"

#define ROLLGRASSWIDTH (0.3f)

namespace lab5
{
	class Lawn
	{
	public:
		Lawn();
		Lawn(double area);
		virtual ~Lawn();

		virtual unsigned int GetArea() const = 0;

		unsigned int GetGrassPrice(eGrassType grassType) const;
		unsigned int GetMinimumSodRollsCount() const;
	
	private:
		double mArea;
	};
}