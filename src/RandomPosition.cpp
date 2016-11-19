#include "RandomPosition.h"

using namespace std;

namespace pEng 
{
	RandomPosition::RandomPosition(const Point minPoint, const Point maxPoint) {
		this->minPoint = minPoint;
		this->maxPoint = maxPoint;
	}

	void RandomPosition::start(vector<Particle> &particles) {
		for (vector<Particle>::iterator i = particles.begin(); i < particles.end(); ++i) {
			Point spawnPos;
			spawnPos.x = (float)rand() / RAND_MAX * (maxPoint.x - minPoint.x) + minPoint.x;
			spawnPos.y = (float)rand() / RAND_MAX * (maxPoint.y - minPoint.y) + minPoint.y;

			(*i).setPosition(spawnPos);
		}
	}

	void RandomPosition::update(vector<Particle> &particles, const float deltaTime) {
	}

	void RandomPosition::reset(vector<Particle> &particles) {
		start(particles);
	}

	ParticleModifier *RandomPosition::copy() {
		ParticleModifier *copy = new RandomPosition(minPoint, maxPoint); 
		return copy;
	}
}