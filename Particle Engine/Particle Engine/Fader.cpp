#include "Fader.h"

using namespace std;

namespace pEng 
{
	Fader::Fader(const float fade_rate) {
		m_fade_rate = fade_rate;
	}

	void Fader::start(vector<Particle> &particles) {
	}

	void Fader::update(vector<Particle> &particles, const float deltaTime) {
		for (vector<Particle>::iterator i = particles.begin(); i < particles.end(); ++i) {
			sf::Color color = (*i).getColor();
			if (color.a - (sf::Uint8)m_fade_rate > 0) {
				color.a -= (sf::Uint8)m_fade_rate;
			} else {
				color.a = 0;
			}

			(*i).setColor(color);
		}
	}

	void Fader::reset(vector<Particle> &particles) {
	}

	ParticleModifier *Fader::copy() {
		ParticleModifier *copy = new Fader(m_fade_rate); 
		return copy;
	}
}