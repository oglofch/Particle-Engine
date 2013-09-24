#ifndef MOVER_H_INCLUDED
#define MOVER_H_INCLUDED

#include <cmath>

#include "ParticleModifier.h"

namespace pEng 
{
	class Mover : public ParticleModifier 
	{
	private:

	public:
		void start(std::vector<Particle> &particles);
		void update(std::vector<Particle> &particles, const float delta);
		void reset(std::vector<Particle> &particles);
	
		ParticleModifier *copy();
	};
}

#endif // MOVER_H_INCLUDED