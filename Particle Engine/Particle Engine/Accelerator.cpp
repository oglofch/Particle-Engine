#include "Accelerator.h"

using namespace std;

namespace pEng 
{
	Accelerator::Accelerator(const float acceleration, const float angle) {
		m_acceleration = acceleration;
		m_angle = angle;
	}

	void Accelerator::start(vector<Particle> &particles) {
	}

	void Accelerator::update(vector<Particle> &particles, const float deltaTime) {
		for (vector<Particle>::iterator i = particles.begin(); i < particles.end(); ++i) {
			Point position = (*i).getPosition();
			Point velocity = (*i).getVelocity();
			velocity.translate(cos(toRadians(m_angle)) * m_acceleration, sin(toRadians(m_angle)) * m_acceleration);
			(*i).setVelocity(velocity);
		}
	}

	void Accelerator::reset(vector<Particle> &particles) {
	}

	ParticleModifier *Accelerator::copy() {
		ParticleModifier *copy = new Accelerator(m_acceleration, m_angle); 
		return copy;
	}
}