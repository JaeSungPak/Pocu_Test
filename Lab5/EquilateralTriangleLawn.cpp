#include "EquilateralTriangleLawn.h"

namespace lab5
{
	EquilateralTriangleLawn::EquilateralTriangleLawn(double width)
		: Lawn((width * width))
	{

	}
	EquilateralTriangleLawn::~EquilateralTriangleLawn()
	{


	}

	unsigned int EquilateralTriangleLawn::GetArea() const
	{
		return 0;
	}

	unsigned int EquilateralTriangleLawn::GetGrassPrice(eGrassType grassType) const
	{
		return 0;
	}
	unsigned int EquilateralTriangleLawn::GetMinimumSodRollsCount() const
	{
		return 0;
	}

	unsigned int EquilateralTriangleLawn::GetMinimumFencesCount() const
	{
		return 0;
	}
	unsigned int EquilateralTriangleLawn::GetFencePrice(eFenceType fenceType) const
	{
		return 0;
	}
}