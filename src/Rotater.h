#ifndef ROTATER_H_INCLUDED
#define ROTATER_H_INCLUDED

#include "ParticleModifier.h"

namespace pEng 
{
	class Rotater : public ParticleModifier {
	private:

	public:
		Rotater();

		void start(std::vector<Particle> &particles);
		void update(std::vector<Particle> &particles, const float delta);
		void reset(std::vector<Particle> &particles);
	
		ParticleModifier *copy();
	};
}

#endif // ROTATER_H_INCLUDED
