#ifndef RANDOM_EXPANSION_RATE_H_INCLUDED
#define RANDOM_EXPANSION_RATE_H_INCLUDED

#include <vector>

#include "ParticleModifier.h"

namespace pEng 
{
	class RandomExpansionRate : public ParticleModifier {
	private:
		float minExpansion;
		float maxExpansion;

	public:
		RandomExpansionRate(const float minExpansion, const float maxExpansion);

		void start(std::vector<Particle> &particles);
		void update(std::vector<Particle> &particles, const float delta);
		void reset(std::vector<Particle> &particles);
	
		ParticleModifier *copy();
	};
}

#endif // RANDOM_EXPANSION_RATE_H_INCLUDED
