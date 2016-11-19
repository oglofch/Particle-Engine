#include "Expander.h"

using namespace std;

namespace pEng 
{
	Expander::Expander() {
	}

	void Expander::start(vector<Particle> &particles) {
	}

	void Expander::update(vector<Particle> &particles, const float deltaTime) {
		for (vector<Particle>::iterator i = particles.begin(); i < particles.end(); ++i) {
			float size = (*i).getSize().x;
			size += (*i).getExpansionRate();

			(*i).setSize(Point(size, size));
		}
	}

	void Expander::reset(vector<Particle> &particles) {
	}

	ParticleModifier *Expander::copy() {
		ParticleModifier *copy = new Expander(); 
		return copy;
	}
}