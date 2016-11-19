#include "Decayer.h"

using namespace std;

namespace pEng 
{
	Decayer::Decayer(const float decay_rate) {
		m_decay_rate = decay_rate;
	}

	void Decayer::start(vector<Particle> &particles) {
	}

	void Decayer::update(vector<Particle> &particles, const float deltaTime) {
		for (vector<Particle>::iterator i = particles.begin(); i < particles.end(); ++i) {
			float life = (*i).getLife();

			(*i).setLife(life - m_decay_rate);
		}
	}

	void Decayer::reset(vector<Particle> &particles) {
	}

	ParticleModifier *Decayer::copy() {
		ParticleModifier *copy = new Decayer(m_decay_rate); 
		return copy;
	}
}