#ifndef RANDOM_POSITION_H_INCLUDED
#define RANDOM_POSITION_H_INCLUDED

#include "ParticleModifier.h"

namespace pEng 
{
	class RandomPosition : public ParticleModifier {
	private:
		Point minPoint;
		Point maxPoint;

	public:
		RandomPosition(const Point minPoint, const Point maxPoint);

		void start(std::vector<Particle> &particles);
		void update(std::vector<Particle> &particles, const float delta);
		void reset(std::vector<Particle> &particles);
	
		ParticleModifier *copy();
	};
}

#endif // RANDOM_POSITION_H_INCLUDED
