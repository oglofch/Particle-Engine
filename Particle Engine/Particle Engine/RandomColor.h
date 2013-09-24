#ifndef RANDOM_COLOR_H_INCLUDED
#define RANDOM_COLOR_H_INCLUDED

#include <cmath>

#include "ParticleModifier.h"

namespace pEng 
{
	class RandomColor : public ParticleModifier 
	{
	private:
		Point red;
		Point blue;
		Point green;
		Point alpha;

	public:
		RandomColor(const Point red, const Point blue, const Point green, const Point alpha = Point(255, 255));

		void start(std::vector<Particle> &particles);
		void update(std::vector<Particle> &particles, const float delta);
		void reset(std::vector<Particle> &particles);
	
		ParticleModifier *copy();
	};
}

#endif // RANDOM_COLOR_H_INCLUDED