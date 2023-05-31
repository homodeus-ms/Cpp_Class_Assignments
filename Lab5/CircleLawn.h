#pragma once

#include "eGrassType.h"

#include "Lawn.h"

namespace lab5
{
	class CircleLawn : public Lawn
	{
	public:
		CircleLawn(unsigned int radius);
		virtual ~CircleLawn();

		unsigned int GetArea() const;

	private:
		unsigned int mRadius;
	};
}