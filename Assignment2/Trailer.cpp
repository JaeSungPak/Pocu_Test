#include "Trailer.h"

namespace assignment2
{
	Trailer::Trailer(unsigned int weight)
		: mWeight(weight)
		, mPointer(this)
	{
	}

	Trailer::~Trailer()
	{
	}

	unsigned int Trailer::GetWeight() const
	{
		return mWeight;
	}
}