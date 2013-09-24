#include "VelocityRenderer.h"

namespace pEng 
{
	void VelocityRenderer::render(sf::RenderWindow &window, std::vector<Particle> &particles, sf::Vector2f offset) {
		for (std::vector<Particle>::iterator i = particles.begin(); i < particles.end(); ++i) {
			Particle particle = (*i);
			
			Point position = particle.getPosition() + offset;
			Point velocity = particle.getVelocity();
			Point size = particle.getSize();

			sf::RectangleShape line(sf::Vector2f(length(velocity), size.x));
			line.rotate(angle(velocity) + particle.getAngle());
			line.setPosition(sf::Vector2f(position.x, position.y));
			line.setFillColor(particle.getColor());

			window.draw(line);
		}
	}

	ParticleRenderer *VelocityRenderer::copy() {
		ParticleRenderer *copy = new VelocityRenderer();
		return copy;
	}
}