#ifndef SPARKLE_H_INCLUDED
#define SPARKLE_H_INCLUDED

#include <cmath>

#include "ParticleModifier.h"

namespace pEng 
{
	class Sparkle : public ParticleModifier 
	{
	private:
		float m_sparkle_rate;

	public:
		Sparkle(const float sparkle_rate);

		void start(std::vector<Particle> &particles);
		void update(std::vector<Particle> &particles, const float delta);
		void reset(std::vector<Particle> &particles);
	
		ParticleModifier *copy();
	};
}
#endif // SPARKLE_H_INCLUDED