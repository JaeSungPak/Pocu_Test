#pragma once

#include "eFenceType.h"

#define FENCEWIDTH (0.25f)

namespace lab5
{
	class IFenceable
	{
	public:
		virtual unsigned int GetMinimumFencesCount() const = 0;
		virtual unsigned int GetFencePrice(eFenceType fenceType) const = 0;
	};
}