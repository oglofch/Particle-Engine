#ifndef _SPRITE_RENDERER_H_
#define _SPRITE_RENDERER_H_

#include "ParticleRenderer.h"

#include "AnimatedSprite.hpp"

namespace pEng 
{
	class SpriteRenderer : public ParticleRenderer
	{
	private:
		sf::Texture *m_texture;
		SpriteAnimation *m_animation;
		AnimatedSprite m_sprite;

	public:
		SpriteRenderer(sf::Texture *texture, SpriteAnimation *animation);
		~SpriteRenderer();

		void render(sf::RenderWindow &window, std::vector<Particle> &particles, sf::Vector2f offset);
	
		ParticleRenderer *copy();
	};
}

#endif