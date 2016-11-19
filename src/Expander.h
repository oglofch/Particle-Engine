#ifndef EXPANDER_H_INCLUDED
#define EXPANDER_H_INCLUDED

#include "ParticleModifier.h"

namespace pEng 
{
	class Expander : public ParticleModifier {
	private:

	public:
		Expander();

		void start(std::vector<Particle> &particles);
		void update(std::vector<Particle> &particles, const float delta);
		void reset(std::vector<Particle> &particles);
	
		ParticleModifier *copy();
	};
}

#endif // EXPANDER_H_INCLUDED
