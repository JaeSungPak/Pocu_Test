#include "EquilateralTriangleLawn.h"
#include <math.h>

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
		double height = sqrt(pow(mWidth, 2) - pow(static_cast<double>(mWidth) / 2, 2));

		return height * mWidth / 2 + 0.5f;
	}

	unsigned int EquilateralTriangleLawn::GetMinimumFencesCount() const
	{
		double result = mWidth * 3 / FENCEWIDTH;

		return result - static_cast<int>(result) == 0 ? result : result + 1;
	}

	unsigned int EquilateralTriangleLawn::GetFencePrice(eFenceType fenceType) const
	{
		return fenceType * mWidth * 3 / 100;
	}
}