#include "TextRenderer.h"

namespace pEng {
	TextRenderer::TextRenderer(std::string fontname) {
		this->fontname = fontname;
		font.loadFromFile(fontname);
		text.setFont(font);
		text.setString("10");
		text.setCharacterSize(5); 
		text.setColor(sf::Color::White);
	}

	void TextRenderer::render(sf::RenderWindow &window, std::vector<Particle> &particles, sf::Vector2f offset) {
		for (std::vector<Particle>::iterator i = particles.begin(); i < particles.end(); ++i) {
			Particle particle = (*i);

			Point position = particle.getPosition() + offset;
			Point velocity = particle.getVelocity();
			Point size = particle.getSize();

			text.setPosition(position.x - 2.0f, position.y - 2.0f);

			window.draw(text);
		}
	}

	ParticleRenderer *TextRenderer::copy() {
		ParticleRenderer *copy = new TextRenderer(fontname);
		return copy;
	}
}