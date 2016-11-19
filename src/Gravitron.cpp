#include "Gravitron.h"

using namespace std;

namespace pEng 
{
	Gravitron::Gravitron(const Point position, const float pull) {
		m_position = position;
		m_pull = pull;
	}

	void Gravitron::start(vector<Particle> &particles) {
	}

	void Gravitron::update(vector<Particle> &particles, const float deltaTime) {
		for (vector<Particle>::iterator i = particles.begin(); i < particles.end(); ++i) {
			Point position = (*i).getPosition();
			Point velocity = (*i).getVelocity();
			float angle = toDegrees(atan2(m_position.y - position.y, m_position.x - position.x));
			float d = pointDistance(position, m_position);
			d = (d == 0 ? (float)0.001 : d);
			velocity.translate(cos(toRadians(angle)) * m_pull * 1/d, sin(toRadians(angle)) * m_pull * 1/d);
			(*i).setVelocity(velocity);
		}
	}

	void Gravitron::reset(vector<Particle> &particles) {
	}

	ParticleModifier *Gravitron::copy() {
		ParticleModifier *copy = new Gravitron(m_position, m_pull); 
		return copy;
	}
}