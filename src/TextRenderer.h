#ifndef _TEXT_RENDERER_H_
#define _TEXT_RENDERER_H_

#include "ParticleRenderer.h"

namespace pEng
{
	class TextRenderer : public ParticleRenderer
	{
	private:
		std::string fontname;
		sf::Font font;
		sf::Text text;

	public:
		TextRenderer(std::string fontname);

		void render(sf::RenderWindow &window, std::vector<Particle> &particles, sf::Vector2f offset);
	
		ParticleRenderer *copy();
	};
}

#endif