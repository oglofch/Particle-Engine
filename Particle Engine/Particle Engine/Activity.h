#ifndef _ACTIVITY_H_
#define _ACTIVITY_H_

#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

class Activity 
{
protected:

public:
	Activity();
	~Activity();

	void start();

	void handleEvent(sf::Event &event);
	void step();
	void update();
	void render();
};

void RenderingThread(Activity *activity);

#endif