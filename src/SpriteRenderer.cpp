#include "SpriteRenderer.h"

namespace pEng 
{
	SpriteRenderer::SpriteRenderer(sf::Texture *texture, SpriteAnimation *animation) {
		m_texture = texture;
		m_animation = animation;

		m_sprite.setAnimation(*animation);
		m_sprite.setOrigin(m_sprite.getGlobalBounds().width/2, m_sprite.getGlobalBounds().height/2);
	}

	SpriteRenderer::~SpriteRenderer() {
		delete m_texture;
		delete m_animation;
	}

	void SpriteRenderer::render(sf::RenderWindow &window, std::vector<Particle> &particles, sf::Vector2f offset) {
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

	ParticleRenderer *SpriteRenderer::copy() {
		// CAN'T COPY THIS YET!
		ParticleRenderer *copy = new SpriteRenderer(m_texture, m_animation);
		return copy;
	}
}