#ifndef BOUNDING_BOX_H_INCLUDED
#define BOUNDING_BOX_H_INCLUDED

#include <cmath>

#include "ParticleModifier.h"

namespace pEng 
{
	class BoundingBox : public ParticleModifier 
	{
	private:
		Point minPos;
		Point maxPos;
		float restitution;

	public:
		 BoundingBox(const Point minPos, const Point maxPos, const float restitution);

		void start(std::vector<Particle> &particles);
		void update(std::vector<Particle> &particles, const float delta);
		void reset(std::vector<Particle> &particles);
	
		ParticleModifier *copy();
	};
}

#endif // BOUNDING_BOX_H_INCLUDED