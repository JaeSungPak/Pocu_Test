#include "CircleLawn.h"

namespace lab5
{
	CircleLawn::CircleLawn(unsigned int radius)
		: mRadius(radius)
	{
		
	}
	CircleLawn::~CircleLawn()
	{

	}

	unsigned int CircleLawn::GetArea() const
	{
		return mRadius * mRadius * 3.14f;
	}

	unsigned int CircleLawn::GetGrassPrice(eGrassType grassType) const
	{
		return 0;
	}
	unsigned int CircleLawn::GetMinimumSodRollsCount() const
	{
		return 0;
	}

	unsigned int CircleLawn::GetMinimumFencesCount() const
	{
		return 0;
	}
	unsigned int CircleLawn::GetFencePrice(eFenceType fenceType) const
	{
		return 0;
	}
}