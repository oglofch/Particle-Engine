#ifndef _VELOCITY_RENDERER_H_
#define _VELOCITY_RENDERER_H_

#include "ParticleRenderer.h"

namespace pEng 
{
	class VelocityRenderer : public ParticleRenderer
	{
	public:
		void render(sf::RenderWindow &window, std::vector<Particle> &particles, sf::Vector2f offset);
	
		ParticleRenderer *copy();
	};
}

#endif