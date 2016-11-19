#include "Sparkle.h"

using namespace std;

namespace pEng 
{
	Sparkle::Sparkle(const float sparkle_rate) {
		m_sparkle_rate = sparkle_rate;
	}

	void Sparkle::start(vector<Particle> &particles) {
	}

	void Sparkle::update(vector<Particle> &particles, const float deltaTime) {
		for (vector<Particle>::iterator i = particles.begin(); i < particles.end(); ++i) {
			sf::Color color = (*i).getColor();
			color.a -= (sf::Uint8)m_sparkle_rate;
			if (color.a == 0) {
				color.a = 255;
			}
			(*i).setColor(color);
		}
	}

	void Sparkle::reset(vector<Particle> &particles) {
	}

	ParticleModifier *Sparkle::copy() {
		ParticleModifier *copy = new Sparkle(m_sparkle_rate); 
		return copy;
	}
}