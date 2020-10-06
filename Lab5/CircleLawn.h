#pragma once

#include "Lawn.h"
#include "IFenceable.h"

#define PIE (3.14f)

namespace lab5
{
	class CircleLawn : public Lawn
	{
	public:
		CircleLawn(unsigned int radius);
		virtual ~CircleLawn();

		virtual unsigned int GetArea() const;

	private:
		unsigned int mRadius;
	};
}