#include "Rotater.h"

using namespace std;

namespace pEng 
{
	Rotater::Rotater() {
	}

	void Rotater::start(vector<Particle> &particles) {
	}

	void Rotater::update(vector<Particle> &particles, const float deltaTime) {
		for (vector<Particle>::iterator i = particles.begin(); i < particles.end(); ++i) {

			(*i).setAngle((*i).getAngle() + (*i).getAngularVelocity());
		}
	}

	void Rotater::reset(vector<Particle> &particles) {
	}

	ParticleModifier *Rotater::copy() {
		ParticleModifier *copy = new Rotater(); 
		return copy;
	}
}