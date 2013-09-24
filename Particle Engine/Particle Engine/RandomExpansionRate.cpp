#include "RandomExpansionRate.h"

using namespace std;

namespace pEng 
{
	RandomExpansionRate::RandomExpansionRate(const float minExpansion, const float maxExpansion) {
		this->minExpansion = minExpansion;
		this->maxExpansion = maxExpansion;
	}

	void RandomExpansionRate::start(vector<Particle> &particles) {
		for (vector<Particle>::iterator i = particles.begin(); i < particles.end(); ++i) {
			(*i).setExpansionRate((float)rand() / RAND_MAX * (maxExpansion - minExpansion) + minExpansion);
		}
	}

	void RandomExpansionRate::update(vector<Particle> &particles, const float deltaTime) {
	}

	void RandomExpansionRate::reset(vector<Particle> &particles) {
		start(particles);
	}

	ParticleModifier *RandomExpansionRate::copy() {
		ParticleModifier *copy = new RandomExpansionRate(minExpansion, maxExpansion); 
		return copy;
	}
}