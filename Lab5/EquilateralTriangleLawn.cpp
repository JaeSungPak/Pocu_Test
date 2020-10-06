#include "EquilateralTriangleLawn.h"

namespace lab5
{
	EquilateralTriangleLawn::EquilateralTriangleLawn(unsigned int width)
		: mWidth(width)
	{

	}
	EquilateralTriangleLawn::~EquilateralTriangleLawn()
	{
	}

	unsigned int EquilateralTriangleLawn::GetArea() const
	{
		return mWidth * mWidth;
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