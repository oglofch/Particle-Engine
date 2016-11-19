#ifndef _PARTICLE_RENDERER_H_
#define _PARTICLE_RENDERER_H_

#include <SFML/Graphics.hpp>
#include <vector>

#include "Particle.h"

namespace pEng 
{
	class ParticleRenderer
	{
	public:
		virtual void render(sf::RenderWindow &window, std::vector<Particle> &particles, sf::Vector2f offset) = 0;
	
		virtual ParticleRenderer *copy() = 0;
	};
}

#endif