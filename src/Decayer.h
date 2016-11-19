#ifndef DECAYER_H_INCLUDED
#define DECAYER_H_INCLUDED

#include <cmath>

#include "ParticleModifier.h"

namespace pEng 
{
	class Decayer : public ParticleModifier 
	{
	private:
		float m_decay_rate;

	public:
		Decayer(const float decay_rate);

		void start(std::vector<Particle> &particles);
		void update(std::vector<Particle> &particles, const float delta);
		void reset(std::vector<Particle> &particles);
	
		ParticleModifier *copy();
	};
}

#endif // DECAYER_H_INCLUDED