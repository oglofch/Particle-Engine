#ifndef INERTIA_H_INCLUDED
#define INERTIA_H_INCLUDED

#include <cmath>

#include "ParticleModifier.h"

namespace pEng 
{
	class Inertia : public ParticleModifier {
	private:
		Point inertia;

	public:
		Inertia(const Point intertia);

		void start(std::vector<Particle> &particles);
		void update(std::vector<Particle> &particles, const float delta);
		void reset(std::vector<Particle> &particles);
	
		ParticleModifier *copy();
	};
}

#endif // RANDOMVELOCITY_H_INCLUDED
