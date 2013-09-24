#include "RandomSize.h"

using namespace std;

namespace pEng 
{
	RandomSize::RandomSize(const float minSize, const float maxSize) {
		this->minSize = minSize;
		this->maxSize = maxSize;
	}

	void RandomSize::start(vector<Particle> &particles) {
		for (vector<Particle>::iterator i = particles.begin(); i < particles.end(); ++i) {
			float size = (float)rand() / RAND_MAX * (maxSize - minSize) + minSize;
		
			(*i).setSize(Point(size, size));
		}
	}

	void RandomSize::update(vector<Particle> &particles, const float deltaTime) {
	}

	void RandomSize::reset(vector<Particle> &particles) {
		start(particles);
	}

	ParticleModifier *RandomSize::copy() {
		ParticleModifier *copy = new RandomSize(minSize, maxSize); 
		return copy;
	}
}