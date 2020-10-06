#pragma once

#include "Lawn.h"
#include "IFenceable.h"

namespace lab5
{
	class RectangleLawn : public Lawn, public IFenceable
	{
	public:
		RectangleLawn(unsigned int height, unsigned int width);
		virtual ~RectangleLawn();

		virtual unsigned int GetArea() const;

		virtual unsigned int GetMinimumFencesCount() const;
		virtual unsigned int GetFencePrice(eFenceType fenceType) const;

	private:
		unsigned int mHeight;
		unsigned int mWidth;
	};
}