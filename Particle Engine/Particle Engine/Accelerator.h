#ifndef ACCELERATOR_H_INCLUDED
#define ACCELERATOR_H_INCLUDED

#include <cmath>

#include "ParticleModifier.h"

namespace pEng 
{
	class Accelerator : public ParticleModifier 
	{
	private:
		float m_angle;
		float m_acceleration;

	public:
		Accelerator(const float acceleration, const float angle);

		void start(std::vector<Particle> &particles);
		void update(std::vector<Particle> &particles, const float delta);
		void reset(std::vector<Particle> &particles);

		ParticleModifier *copy();
	};
}

#endif // ACCELERATOR_H_INCLUDED
