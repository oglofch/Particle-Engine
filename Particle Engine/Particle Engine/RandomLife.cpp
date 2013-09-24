#include "RandomLife.h"

using namespace std;

namespace pEng 
{
	RandomLife::RandomLife(const float minLife, const float maxLife) {
		this->minLife = minLife;
		this->maxLife = maxLife;
	}

	void RandomLife::start(vector<Particle> &particles) {
		for (vector<Particle>::iterator i = particles.begin(); i < particles.end(); ++i) {
			(*i).setLife((float)rand() / RAND_MAX * (maxLife - minLife) + minLife);
		}
	}

	void RandomLife::update(vector<Particle> &particles, const float deltaTime) {
	}

	void RandomLife::reset(vector<Particle> &particles) {
		start(particles);
	}

	ParticleModifier *RandomLife::copy() {
		ParticleModifier *copy = new RandomLife(minLife, minLife); 
		return copy;
	}
}