#ifndef GRAVITRON_H_INCLUDED
#define GRAVITRON_H_INCLUDED

#include <cmath>

#include "ParticleModifier.h"

namespace pEng 
{
	class Gravitron : public ParticleModifier {
	private:
		Point m_position;
		float m_pull;

	public:
		Gravitron(const Point position, const float pull);

		void start(std::vector<Particle> &particles);
		void update(std::vector<Particle> &particles, const float delta);
		void reset(std::vector<Particle> &particles);

		ParticleModifier *copy();
	};
}

#endif // GRAVITRON_H_INCLUDED
