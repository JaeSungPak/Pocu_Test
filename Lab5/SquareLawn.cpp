#include "SquareLawn.h"

namespace lab5
{
	SquareLawn::SquareLawn(double height)
		:Lawn(height * height)
	{

	}
	SquareLawn::~SquareLawn()
	{


	}

	unsigned int SquareLawn::GetArea() const
	{
		return 0;
	}

	unsigned int SquareLawn::GetGrassPrice(eGrassType grassType) const
	{
		return 0;
	}
	unsigned int SquareLawn::GetMinimumSodRollsCount() const
	{
		return 0;
	}

	unsigned int SquareLawn::GetMinimumFencesCount() const
	{
		return 0;
	}
	unsigned int SquareLawn::GetFencePrice(eFenceType fenceType) const
	{
		return 0;
	}
}