#include "SquareLawn.h"

namespace lab5
{
	SquareLawn::SquareLawn(unsigned int height)
		:mHeight(height)
	{

	}
	SquareLawn::~SquareLawn()
	{


	}

	unsigned int SquareLawn::GetArea() const
	{
		return mHeight * mHeight;
	}

	unsigned int SquareLawn::GetMinimumFencesCount() const
	{
		double result = mHeight * 4 / FENCEWIDTH;

		return result - static_cast<int>(result) == 0 ? result : result + 1;
	}

	unsigned int SquareLawn::GetFencePrice(eFenceType fenceType) const
	{
		return fenceType * mHeight * 4 / 100;
	}
}