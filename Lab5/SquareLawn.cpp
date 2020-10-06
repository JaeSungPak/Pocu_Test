#include "SquareLawn.h"

namespace lab5
{
	SquareLawn::SquareLawn(unsigned int height)
		: RectangleLawn(height, height)
	{
	}
	SquareLawn::~SquareLawn()
	{

	}

	unsigned int SquareLawn::GetArea() const
	{
		return RectangleLawn::GetArea();
	}

	unsigned int SquareLawn::GetMinimumFencesCount() const
	{
		return RectangleLawn::GetMinimumFencesCount();
	}

	unsigned int SquareLawn::GetFencePrice(eFenceType fenceType) const
	{
		return RectangleLawn::GetFencePrice(fenceType);
	}
}