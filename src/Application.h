#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include <SFML/Graphics.hpp>

#include "ParticleManager.h"
#include "Constants.h"

class core
{
private:
    // Private Constructor
	core();

    // Stop the compiler generating methods of copy the object
    core(core const& copy);            // Not Implemented
    core& operator=(core const& copy); // Not Implemented

public:
    static core& instance();

	/* MANAGERS */
	ParticleManager particleManager;

	/* GRAPHICS */
	sf::VideoMode vidMode;
	sf::RenderWindow window;
};

#endif