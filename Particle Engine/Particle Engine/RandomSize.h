#ifndef RANDOM_SIZEE_H_INCLUDED
#define RANDOM_SIZE_H_INCLUDED

#include "ParticleModifier.h"

namespace pEng 
{
	class RandomSize : public ParticleModifier {
	private:
		float minSize;
		float maxSize;

	public:
		RandomSize(const float minSize, const float maxSize);

		void start(std::vector<Particle> &particles);
		void update(std::vector<Particle> &particles, const float delta);
		void reset(std::vector<Particle> &particles);
	
		ParticleModifier *copy();
	};
}

#endif // RANDOM_SIZE_H_INCLUDED
