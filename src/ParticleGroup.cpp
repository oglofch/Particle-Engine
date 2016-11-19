#include "ParticleGroup.h"

using namespace std;

#include "Application.h"

#include "Particle.h"

namespace pEng 
{
	ParticleGroup::ParticleGroup() {
		m_numParticles = 0;
		setPosition(sf::Vector2f(0, 0));
		setRevive(true);
		m_physics = false;
	}

	ParticleGroup::ParticleGroup(const int numParticles) {
		m_numParticles = numParticles;
		setPosition(sf::Vector2f(0, 0));
		setRevive(true);
		for (int i = 0; i < numParticles; ++i) {
			Particle particle = Particle();
			aliveParticles.push_back(particle);
		}
		m_physics = false;
	}

	ParticleGroup::~ParticleGroup() {
		for (vector<Particle>::iterator i = aliveParticles.begin(); i != aliveParticles.end(); ++i) {
			//b2Body *body = (*i).getBody();
			
			//if (body != NULL) {
				/* TODO: Make sure this gets deleted */
				//body->GetWorld()->DestroyBody(body);
			//}
		}
		for (vector<ParticleModifier*>::iterator i = modifiers.begin() ; i != modifiers.end(); ++i) {
			delete (*i);
		}
		for (vector<ParticleRenderer*>::iterator i = renderers.begin() ; i != renderers.end(); ++i) {
			delete (*i);
		}
	}

	void ParticleGroup::createParticleBodies() {
		/*for (std::vector<Particle>::iterator i = aliveParticles.begin(); i != aliveParticles.end(); ++i) {
			Point size = (*i).getSize();
			Point position = (*i).getPosition();
			Point velocity = (*i).getVelocity();

			b2Body *body = (*i).getBody();
			b2BodyDef bodyDef;
			b2FixtureDef fixDef;
			b2PolygonShape shape;
			b2CircleShape wheel;

			bodyDef.position = b2Vec2(position.x/PPM, position.y/PPM);
			bodyDef.type = b2_dynamicBody;
			bodyDef.fixedRotation = false;
			body = core::instance().entityManager.getWorld().CreateBody(&bodyDef);

			shape.SetAsBox(size.x/2/PPM, size.y/2/PPM);
			fixDef.friction = randFloat(0.002f, 0.008f);
			fixDef.density = 0.0f;
			fixDef.restitution = randFloat(0.1f, 0.6f);
			fixDef.isSensor = false;
			fixDef.shape = &shape;
			fixDef.filter.categoryBits = PARTICLE;
			fixDef.filter.maskBits = TERRAIN;
			fixDef.userData = NULL;

			body->CreateFixture(&fixDef);
			body->SetLinearVelocity(b2Vec2(velocity.x/PPM, velocity.y/PPM));

			(*i).setBody(body);
		}*/
	}

	void ParticleGroup::clearBodies() {
		for (vector<Particle>::iterator i = aliveParticles.begin(); i != aliveParticles.end(); ++i) {
			//b2Body *body = (*i).getBody();
			
			/*if (body != NULL) {
				body->GetWorld()->DestroyBody(body);
			}*/
		}
	}

	void ParticleGroup::setPosition(sf::Vector2f position) {
		m_position = position;
	}

	void ParticleGroup::reset(int capacity) {
		aliveParticles.clear();
		deadParticles.clear();
		m_numParticles = capacity;
		setPosition(sf::Vector2f(0, 0));
		setRevive(true);
		setPhysics(false);
		for (int i = 0; i < capacity; ++i) {
			Particle particle = Particle();
			aliveParticles.push_back(particle);
		}
		for (vector<ParticleModifier*>::iterator i = modifiers.begin() ; i != modifiers.end(); ++i) {
			delete (*i);
		}
		for (vector<ParticleRenderer*>::iterator i = renderers.begin() ; i != renderers.end(); ++i) {
			delete (*i);
		}
		modifiers.clear();
		renderers.clear();
	}

	void ParticleGroup::setRevive(const bool revive) {
		this->revive = revive;
	}

	void ParticleGroup::set(const int numParticles) {
		aliveParticles.clear();
		deadParticles.clear();
		for (int i = 0; i < numParticles; ++i) {
			Particle particle = Particle();
			aliveParticles.push_back(particle);
		}
	}

	void ParticleGroup::update(const float delta) {
		for (vector<ParticleModifier*>::iterator i = modifiers.begin() ; i != modifiers.end(); ++i) {
			(*i)->update(aliveParticles, delta);
		}
		for (vector<Particle>::iterator i = aliveParticles.begin() ; i != aliveParticles.end(); ++i) {
			/*b2Body *body = (*i).getBody();
			if (body != NULL) {
				b2Vec2 position = body->GetPosition();
				float angle = body->GetAngle();

				(*i).setPosition(Point(position.x*PPM, position.y*PPM));
				(*i).setAngle(angle);
			}*/
		}
		vector<Particle>::iterator i = aliveParticles.begin();
		while(i != aliveParticles.end()) {
			Particle p = (*i);

			if (!p.isAlive()) {
				deadParticles.push_back(p);
				//b2Body *body = p.getBody();
			
				/*if (body != NULL) {
					body->GetWorld()->DestroyBody(body);
				}*/
				i = aliveParticles.erase(i);
			} else {
				i++;
			}
		}

		if (!deadParticles.empty() && this->revive) {
			for (vector<Particle>::iterator i = deadParticles.begin() ; i != deadParticles.end(); ++i) {
				(*i).reset();
			}

			for (vector<ParticleModifier*>::iterator i = modifiers.begin() ; i != modifiers.end(); ++i) {
				(*i)->reset(deadParticles);
			}

			vector<Particle>::iterator i = deadParticles.begin();
			while(i != deadParticles.end()) {
				Particle p = (*i);

				aliveParticles.push_back(p);
				i = deadParticles.erase(i);
			}
		}
	}

	void ParticleGroup::render(sf::RenderWindow &window) {
		for (vector<ParticleRenderer*>::iterator i = renderers.begin() ; i != renderers.end(); ++i) {
			ParticleRenderer *renderer = (*i);

			renderer->render(window, aliveParticles, m_position);
		}
	}

	void ParticleGroup::addModifier(ParticleModifier *modifier) {
		modifiers.push_back(modifier);
	}

	void ParticleGroup::addRenderer(ParticleRenderer *renderer) {
		renderers.push_back(renderer);
	}

	
	void ParticleGroup::setPhysics(bool physics) {
		m_physics = physics;
	}

	bool ParticleGroup::hasPhysics() {
		return m_physics;
	}

	void ParticleGroup::start() {
		for (vector<Particle>::iterator i = deadParticles.begin(); i < deadParticles.end(); ++i) {
			aliveParticles.push_back(*i);
		}
		deadParticles.clear();

		for (vector<ParticleModifier*>::iterator i = modifiers.begin(); i < modifiers.end(); ++i) {
			(*i)->start(aliveParticles);
		}
	}

	ParticleGroup *ParticleGroup::copy() {
		ParticleGroup *copy = core::instance().particleManager.getParticleGroup(m_numParticles);
		copy->setRevive(revive);
		copy->setPosition(m_position);
		copy->setPhysics(m_physics);
		for (vector<ParticleModifier*>::iterator i = modifiers.begin(); i < modifiers.end(); ++i) {
			copy->addModifier((*i)->copy());
		}
		for (vector<ParticleRenderer*>::iterator i = renderers.begin() ; i != renderers.end(); ++i) {
			copy->addRenderer((*i)->copy());
		}
		return copy;
	}

	bool ParticleGroup::isAlive() {
		return !aliveParticles.empty() || this->revive;
	}
}