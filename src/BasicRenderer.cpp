#include "BasicRenderer.h"

namespace pEng 
{
	void BasicRenderer::render(sf::RenderWindow &window, std::vector<Particle> &particles, sf::Vector2f offset) {
		sf::VertexArray point(sf::Points, particles.size());

		for (std::vector<Particle>::iterator i = particles.begin(); i < particles.end(); ++i) {
			Particle particle = (*i);
			
			Point position = particle.getPosition() + offset;
			Point velocity = particle.getVelocity();
			Point size = particle.getSize();

			point[i - particles.begin()].position = sf::Vector2f(position.x, position.y);
			point[i - particles.begin()].color = particle.getColor();
		}
		window.draw(point);
	}

	ParticleRenderer *BasicRenderer::copy() {
		ParticleRenderer *copy = new BasicRenderer();
		return copy;
	}
}