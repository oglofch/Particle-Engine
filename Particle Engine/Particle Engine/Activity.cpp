#include "Activity.h"

#include "Application.h"

Activity::Activity() {
}

Activity::~Activity() {
}

void Activity::start() {
	sf::Event event;
	sf::Clock clock;
	clock.restart();
	render();

    while (core::instance().window.isOpen())
    {
        if (core::instance().window.pollEvent(event)) {
			handleEvent(event);
		}

		step();
		update();
		render();
    }
}

void Activity::handleEvent(sf::Event &event) {
	switch (event.type)
	{
		case sf::Event::Closed:
			core::instance().window.close();
			break;

		case sf::Event::Resized:
			break;

		case sf::Event::GainedFocus:
			break;

		case sf::Event::LostFocus:
			break;

		// we don't process other types of events, send to layers
		default:
			break;
	}
}

void Activity::step() {
}

void Activity::update() {
	core::instance().particleManager.update();
}

void Activity::render() {
	// clear
	core::instance().window.clear();

	core::instance().particleManager.render();

	core::instance().window.display();
}