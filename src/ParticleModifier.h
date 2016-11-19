#ifndef PARTICLEMODIFIER_H_INCLUDED
#define PARTICLEMODIFIER_H_INCLUDED

#include <cstdlib>
#include <vector>

#include "Utility.h"
#include "Particle.h"

namespace pEng 
{
	class ParticleModifier
	{
	public:
		virtual void start(std::vector<Particle> &particles) = 0;
		virtual void update(std::vector<Particle> &particles, const float delta) = 0;
		virtual void reset(std::vector<Particle> &particles) = 0;

		virtual ParticleModifier *copy() = 0;
	};
}

#endif // PARTICLEMODIFIER_H_INCLUDED
