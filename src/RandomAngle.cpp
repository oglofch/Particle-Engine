#include "RandomAngle.h"

using namespace std;

namespace pEng 
{
	RandomAngle::RandomAngle(const float minRotation, const float maxRotation) {
		this->minRotation = minRotation;
		this->maxRotation = maxRotation;
	}

	void RandomAngle::start(vector<Particle> &particles) {
		for (vector<Particle>::iterator i = particles.begin(); i < particles.end(); ++i) {
			(*i).setAngle((float)rand() / RAND_MAX * (maxRotation - minRotation) + minRotation);
		}
	}

	void RandomAngle::update(vector<Particle> &particles, const float deltaTime) {
	}

	void RandomAngle::reset(vector<Particle> &particles) {
		start(particles);
	}

	ParticleModifier *RandomAngle::copy() {
		ParticleModifier *copy = new RandomAngle(minRotation, maxRotation); 
		return copy;
	}
}