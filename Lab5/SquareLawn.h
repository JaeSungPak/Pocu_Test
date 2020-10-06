#pragma once

#include "Lawn.h"
#include "IFenceable.h"

namespace lab5
{
	class SquareLawn : public Lawn, public IFenceable
	{
	public:
		SquareLawn(double height);
		virtual ~SquareLawn();

		virtual unsigned int GetArea() const;

		unsigned int GetGrassPrice(eGrassType grassType) const;
		unsigned int GetMinimumSodRollsCount() const;

		virtual unsigned int GetMinimumFencesCount() const;
		virtual unsigned int GetFencePrice(eFenceType fenceType) const;
	};
}