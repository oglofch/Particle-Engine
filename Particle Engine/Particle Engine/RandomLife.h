#ifndef RANDOM_LIFE_H_INCLUDED
#define RANDOM_LIFE_H_INCLUDED

#include "ParticleModifier.h"

namespace pEng 
{
	class RandomLife : public ParticleModifier {
	private:
		float minLife;
		float maxLife;

	public:
		RandomLife(const float minLife, const float maxLife);

		void start(std::vector<Particle> &particles);
		void update(std::vector<Particle> &particles, const float delta);
		void reset(std::vector<Particle> &particles);
	
		ParticleModifier *copy();
	};
}

#endif // RANDOMLIFE_H_INCLUDED
