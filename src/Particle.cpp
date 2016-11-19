#include "Particle.h"

namespace pEng 
{
	Particle::Particle() {
		reset();
	}

	void Particle::reset() {
		life = 0.0f;
		angularVelocity = 0.0f;
		angle = 0.0f;
		expansionRate = 0.0f;
		decayRate = 0.0f;
		color = sf::Color(0, 0, 0);
		position.set(0, 0);
		size.set(0, 0);
		velocity.set(0, 0);
		text = "";
	}

	Particle::~Particle() {
	}

	sf::Color Particle::getColor() {
		return this->color;
	}

	Point Particle::getPosition() {
		return position;
	}

	Point Particle::getVelocity() {
		//if (m_body == NULL) {
			return velocity;
		//} else {
			//b2Vec2 velocity = m_body->GetLinearVelocity();

			//return Point(velocity.x, velocity.y);
		//}
	}

	Point Particle::getSize() {
		return size;
	}

	float Particle::getLife() {
		return life;
	}

	float Particle::getExpansionRate() {
		return expansionRate;
	}

	float Particle::getDecayRate() {
		return decayRate;
	}

	float Particle::getAngularVelocity() {
		return angularVelocity;
	}

	float Particle::getAngle() {
		return angle;
	}

	std::string Particle::getText() {
		return text;
	}

	/*b2Body *Particle::getBody() {
		return m_body;
	}*/

	void Particle::setColor(sf::Color color) {
		this->color = color;
	}

	void Particle::setPosition(const Point position) {
		this->position = position;
	}

	void Particle::setVelocity(const Point velocity) {
		this->velocity = velocity;
	}

	void Particle::setSize(const Point size) {
		this->size = size;
	}

	void Particle::setLife(const float lifetime) {
		this->life = lifetime;
	}

	void Particle::setExpansionRate(const float expansionRate) {
		this->expansionRate = expansionRate;
	}

	void Particle::setDecayRate(const float decayRate) {
		this->decayRate = decayRate;
	}

	void Particle::setAngularVelocity(const float angularVelocity) {
		this->angularVelocity = angularVelocity;
	}

	void Particle::setAngle(const float angle) {
		this->angle = angle;
	}

	void Particle::setText(const std::string text) {
		this->text = text;
	}

	/*void Particle::setBody(b2Body *body) {
		m_body = body;
	}*/

	bool Particle::isAlive() {
		return (life >= 0 && color.a > 0 && size.x > 0 && size.y > 0);
	}
}