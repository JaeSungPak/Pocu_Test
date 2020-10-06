#pragma once

#include "Lawn.h"
#include "IFenceable.h"

#define PIE (3.14f)

namespace lab5
{
	class CircleLawn : public Lawn, public IFenceable
	{
	public:
		CircleLawn(unsigned int radius);
		virtual ~CircleLawn();

		virtual unsigned int GetArea() const;

		unsigned int GetGrassPrice(eGrassType grassType) const;
		unsigned int GetMinimumSodRollsCount() const;

		virtual unsigned int GetMinimumFencesCount() const;
		virtual unsigned int GetFencePrice(eFenceType fenceType) const;

	private:
		unsigned int mRadius;
	};
}