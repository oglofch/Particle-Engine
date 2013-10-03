#include "VelocityRenderer.h"

namespace pEng 
{
	void VelocityRenderer::render(sf::RenderWindow &window, std::vector<Particle> &particles, sf::Vector2f offset) {
		sf::VertexArray line(sf::Lines, particles.size()*2);

		for (std::vector<Particle>::iterator i = particles.begin(); i < particles.end(); ++i) {
			Particle particle = (*i);
			
			Point position = particle.getPosition() + offset;
			Point velocity = particle.getVelocity();
			Point size = particle.getSize();

			line[(i - particles.begin()) * 2].position = sf::Vector2f(position.x, position.y);
			line[(i - particles.begin()) * 2].color = particle.getColor();

			line[(i - particles.begin()) * 2 + 1].position = sf::Vector2f(position.x - velocity.x, position.y - velocity.y);
			line[(i - particles.begin()) * 2 + 1].color = particle.getColor();

		}
		window.draw(line);
	}

	ParticleRenderer *VelocityRenderer::copy() {
		ParticleRenderer *copy = new VelocityRenderer();
		return copy;
	}
}