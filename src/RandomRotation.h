#ifndef RANDOM_ROTATION_H_INCLUDED
#define RANDOM_ROTATION_H_INCLUDED

#include "ParticleModifier.h"

namespace pEng 
{
	class RandomRotation : public ParticleModifier {
	private:
		float minRotation;
		float maxRotation;

	public:
		RandomRotation(const float minRotation, const float maxRotation);

		void start(std::vector<Particle> &particles);
		void update(std::vector<Particle> &particles, const float delta);
		void reset(std::vector<Particle> &particles);
	
		ParticleModifier *copy();
	};
}

#endif // RANDOM_ROTATION_H_INCLUDED
