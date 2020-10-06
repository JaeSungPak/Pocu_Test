#include "RectangleLawn.h"

namespace lab5
{
	RectangleLawn::RectangleLawn(unsigned int height, unsigned int width)
		: mHeight(height)
		, mWidth(width)
	{

	}
	RectangleLawn::~RectangleLawn()
	{


	}

	unsigned int RectangleLawn::GetArea() const
	{
		return mHeight * mWidth;
	}

	unsigned int RectangleLawn::GetMinimumFencesCount() const
	{
		double result = (mHeight + mWidth) * 2 / FENCEWIDTH;

		return static_cast<unsigned int>(result - static_cast<int>(result) == 0 ? result : result + 1);
	}

	unsigned int RectangleLawn::GetFencePrice(eFenceType fenceType) const
	{
		return fenceType * (mHeight + mWidth) * 2 / 100;
	}
}