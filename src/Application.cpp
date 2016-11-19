#include "Application.h"

core::core() {
	srand(time(NULL));

	vidMode.width = 900;
	vidMode.height = 300;
	vidMode.bitsPerPixel = 32;

	sf::ContextSettings settings;

	window.create(vidMode, "Particle Engine Example", sf::Style::Default, settings);
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(false);
}

core &core::instance() {
	// The only instance
    // Guaranteed to be lazy initialized
    // Guaranteed that it will be destroyed correctly
    static core instance;
    return instance;
}