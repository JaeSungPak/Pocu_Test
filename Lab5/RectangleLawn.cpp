#include "RectangleLawn.h"

namespace lab5
{
	RectangleLawn::RectangleLawn(unsigned int height, unsigned int width)
		:Lawn(height * width)
	{

	}
	RectangleLawn::~RectangleLawn()
	{


	}

	unsigned int RectangleLawn::GetArea() const
	{
		return 0;
	}

	unsigned int RectangleLawn::GetGrassPrice(eGrassType grassType) const
	{
		return 0;
	}
	unsigned int RectangleLawn::GetMinimumSodRollsCount() const
	{
		return 0;
	}

	unsigned int RectangleLawn::GetMinimumFencesCount() const
	{
		return 0;
	}
	unsigned int RectangleLawn::GetFencePrice(eFenceType fenceType) const
	{
		return 0;
	}
}