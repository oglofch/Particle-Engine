#ifndef RANDOMVELOCITY_H_INCLUDED
#define RANDOMVELOCITY_H_INCLUDED

#include <cmath>

#include "ParticleModifier.h"

namespace pEng 
{
	class RandomVelocity : public ParticleModifier {
	private:
		Point speedRange;
		Point angleRange;

	public:
		RandomVelocity(const Point speedRange, const Point angleRange);

		void start(std::vector<Particle> &particles);
		void update(std::vector<Particle> &particles, const float delta);
		void reset(std::vector<Particle> &particles);
	
		ParticleModifier *copy();
	};
}

#endif // RANDOMVELOCITY_H_INCLUDED
