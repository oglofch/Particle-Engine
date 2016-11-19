#include "RandomRotation.h"

using namespace std;

namespace pEng 
{
	RandomRotation::RandomRotation(const float minRotation, const float maxRotation) {
		this->minRotation = minRotation;
		this->maxRotation = maxRotation;
	}

	void RandomRotation::start(vector<Particle> &particles) {
		for (vector<Particle>::iterator i = particles.begin(); i < particles.end(); ++i) {
			(*i).setAngularVelocity((float)rand() / RAND_MAX * (maxRotation - minRotation) + minRotation);
		}
	}

	void RandomRotation::update(vector<Particle> &particles, const float deltaTime) {
	}

	void RandomRotation::reset(vector<Particle> &particles) {
		start(particles);
	}

	ParticleModifier *RandomRotation::copy() {
		ParticleModifier *copy = new RandomRotation(minRotation, minRotation); 
		return copy;
	}
}