#ifndef PARTICLE_H_INCLUDED
#define PARTICLE_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>

//#include "Application.h"
#include "Point.h"

//class b2Body;

namespace pEng 
{
	class Particle
	{
	private:
		sf::Color color;
		Point position;
		Point size;
		float life;
		float angle;

		Point velocity;
		float angularVelocity;
		float expansionRate;
		float decayRate;

		std::string text;

		//b2Body *m_body;

	public:
		Particle();
		~Particle();

		void reset();

		sf::Color getColor();
		Point getPosition();
		Point getVelocity();
		Point getSize();
		float getLife();
		float getExpansionRate();
		float getDecayRate();
		float getAngularVelocity();
		float getAngle();
		std::string getText();
		//b2Body *getBody();

		void setColor(sf::Color color);
		void setPosition(const Point position);
		void setVelocity(const Point velocity);
		void setSize(const Point size);
		void setLife(const float life);
		void setExpansionRate(const float expansionRate);
		void setDecayRate(const float decayRate);
		void setAngularVelocity(const float angularVelocity);
		void setAngle(const float angle);
		void setText(const std::string text);
		//void setBody(b2Body *body);

		bool isAlive();
	};
}

#endif // PARTICLE_H_INCLUDED
