#include "BasicRenderer.h"

namespace pEng 
{
	void BasicRenderer::render(sf::RenderWindow &window, std::vector<Particle> &particles, sf::Vector2f offset) {
		sf::RectangleShape shape;

		for (std::vector<Particle>::iterator i = particles.begin(); i < particles.end(); ++i) {
			Particle particle = (*i);
			
			Point position = particle.getPosition() + offset;
			Point velocity = particle.getVelocity();
			Point size = particle.getSize();

			shape.setOrigin(sf::Vector2f(size.x / 2, size.y / 2));
			shape.setSize(sf::Vector2f(size.x, size.y));
			shape.setFillColor(particle.getColor());
			shape.setPosition(position.x - 2.0f, position.y - 2.0f);
			shape.setRotation(particle.getAngle());

			window.draw(shape);
		}
	}

	ParticleRenderer *BasicRenderer::copy() {
		ParticleRenderer *copy = new BasicRenderer();
		return copy;
	}
}