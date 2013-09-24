#include "Inertia.h"

using namespace std;

namespace pEng 
{
	Inertia::Inertia(const Point inertia) {
		this->inertia = inertia;
	}

	void Inertia::start(vector<Particle> &particles) {
		for (vector<Particle>::iterator i = particles.begin(); i < particles.end(); ++i) {
			(*i).setVelocity((*i).getVelocity() + inertia / Point(200, 200));
		}
	}

	void Inertia::update(vector<Particle> &particles, const float deltaTime) {
	}

	void Inertia::reset(vector<Particle> &particles) {
		start(particles);
	}

	ParticleModifier *Inertia::copy() {
		ParticleModifier *copy = new Inertia(inertia); 
		return copy;
	}
}
