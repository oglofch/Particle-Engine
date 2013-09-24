#include "BoundingBox.h"

using namespace std;

namespace pEng 
{
	BoundingBox::BoundingBox(const Point minPos, const Point maxPos, const float restitution) {
		this->minPos = minPos;
		this->maxPos = maxPos;
		this->restitution = restitution;
	}

	void BoundingBox::start(vector<Particle> &particles) {
	}

	void BoundingBox::update(vector<Particle> &particles, const float deltaTime) {
		for (vector<Particle>::iterator i = particles.begin(); i < particles.end(); ++i) {
			Point position = (*i).getPosition();
			Point velocity = (*i).getVelocity();

			if (position.x < minPos.x) {
				position.x = minPos.x;
				velocity = Point(velocity.x * -restitution, velocity.y);
			} else if (position.x > maxPos.x) {
				position.x = maxPos.x;
				velocity = Point(velocity.x * -restitution, velocity.y);
			}
			if (position.y < minPos.y) {
				position.y = minPos.y;
				velocity = Point(velocity.x, velocity.y * -restitution);
			} else if (position.y > maxPos.y) {
				position.y = maxPos.y;
				velocity = Point(velocity.x, velocity.y * -restitution);
			}

			(*i).setPosition(position);
			(*i).setVelocity(velocity);
		}
	}

	void BoundingBox::reset(vector<Particle> &particles) {
	}

	ParticleModifier *BoundingBox::copy() {
		ParticleModifier *copy = new BoundingBox(minPos, maxPos, restitution); 
		return copy;
	}
}