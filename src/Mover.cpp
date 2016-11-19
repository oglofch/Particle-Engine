#include "Mover.h"

using namespace std;

namespace pEng 
{
	void Mover::start(vector<Particle> &particles) {
	}

	void Mover::update(vector<Particle> &particles, const float deltaTime) {
		for (vector<Particle>::iterator i = particles.begin(); i < particles.end(); ++i) {
			Point position = (*i).getPosition();
			Point velocity = (*i).getVelocity();

			position.translate(velocity.x, velocity.y);
			(*i).setPosition(position);
		}
	}

	void Mover::reset(vector<Particle> &particles) {
	}

	ParticleModifier *Mover::copy() {
		ParticleModifier *copy = new Mover(); 
		return copy;
	}
}