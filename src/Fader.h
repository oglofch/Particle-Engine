#ifndef FADER_H_INCLUDED
#define FADER_H_INCLUDED

#include <cmath>

#include "ParticleModifier.h"

namespace pEng 
{
	class Fader : public ParticleModifier 
	{
	private:
		float m_fade_rate;

	public:
		Fader(const float fade_rate);

		void start(std::vector<Particle> &particles);
		void update(std::vector<Particle> &particles, const float delta);
		void reset(std::vector<Particle> &particles);
	
		ParticleModifier *copy();
	};
}
#endif // FADER_H_INCLUDED