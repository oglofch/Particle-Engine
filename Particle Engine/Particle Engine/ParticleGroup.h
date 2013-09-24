#ifndef PARTICLEGROUP_H_INCLUDED
#define PARTICLEGROUP_H_INCLUDED

#include <vector>

#include "ParticleRenderer.h"
#include "ParticleModifier.h"
#include "Particle.h"

namespace pEng 
{
	class ParticleGroup
	{
	private:
		std::vector<Particle> aliveParticles;
		std::vector<Particle> deadParticles;
		std::vector<ParticleModifier*> modifiers;

		int m_numParticles;
		bool revive;
		bool m_physics;

		sf::Vector2f m_position;

		std::vector<ParticleRenderer*> renderers;

	public:
		ParticleGroup();
		ParticleGroup(const int numParticles);
		~ParticleGroup();

		void setPosition(sf::Vector2f position);
		void reset(int capacity);
		void setRevive(const bool revive);
		void set(const int numParticles);
		void update(const float delta);
		void render(sf::RenderWindow &window);
		void addModifier(ParticleModifier *modifier);
		void start();
		void addRenderer(ParticleRenderer *renderer);

		void setPhysics(bool physics);
		bool hasPhysics();

		ParticleGroup *copy();

		bool isAlive();

		void createParticleBodies();
		void clearBodies();
	};
}

#endif // PARTICLEGROUP_H_INCLUDED
