#include "RandomVelocity.h"

using namespace std;

namespace pEng 
{
	RandomVelocity::RandomVelocity(const Point speedRange, const Point angleRange) {
		this->speedRange = speedRange;
		this->angleRange = angleRange;
	}

	void RandomVelocity::start(vector<Particle> &particles) {
		for (vector<Particle>::iterator i = particles.begin(); i < particles.end(); ++i) {
			float speed = (float)rand() / RAND_MAX * (speedRange.y - speedRange.x) + speedRange.x;
			float angle = (float)rand() / RAND_MAX * (angleRange.y - angleRange.x) + angleRange.x;
			Point velocity(cos(toRadians(angle)) * speed, sin(toRadians(angle)) * speed);

			(*i).setVelocity((*i).getVelocity() + velocity);
		}
	}

	void RandomVelocity::update(vector<Particle> &particles, const float deltaTime) {
	}

	void RandomVelocity::reset(vector<Particle> &particles) {
		start(particles);
	}

	ParticleModifier *RandomVelocity::copy() {
		ParticleModifier *copy = new RandomVelocity(speedRange, angleRange); 
		return copy;
	}
}
