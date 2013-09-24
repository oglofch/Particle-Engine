#include "RandomColor.h"

using namespace std;

namespace pEng 
{
	RandomColor::RandomColor(const Point red, const Point green, const Point blue, const Point alpha) {
		this->red = red;
		this->blue = blue;
		this->green = green;
		this->alpha = alpha;
	}

	void RandomColor::start(vector<Particle> &particles) {
		for (vector<Particle>::iterator i = particles.begin(); i < particles.end(); ++i) {
			if (alpha.x != 255 && alpha.y != 255) {
				(*i).setColor(sf::Color(sf::Uint8(randInt(red.x, red.y)), 
					sf::Uint8(randInt(green.x, green.y)), 
					sf::Uint8(randInt(blue.x, blue.y)), 
					sf::Uint8(randInt(alpha.x, alpha.y))));
			} else {
				(*i).setColor(sf::Color(sf::Uint8(randInt(red.x, red.y)), 
					sf::Uint8(randInt(green.x, green.y)), 
					sf::Uint8(randInt(blue.x, blue.y))));
			}
		}
	}

	void RandomColor::update(vector<Particle> &particles, const float deltaTime) {
	}

	void RandomColor::reset(vector<Particle> &particles) {
		start(particles);
	}

	ParticleModifier *RandomColor::copy() {
		ParticleModifier *copy = new RandomColor(red, green, blue, alpha); 
		return copy;
	}
}