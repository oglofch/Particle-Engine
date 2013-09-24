#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <vector>
#include <map>

#include <SFML/Graphics.hpp>

#include "Application.h"
#include "Constants.h"
#include "Utility.h"
#include "Component.h"

class Player;

enum EntityType {
	DEFAULT = 0x001,
	PLAYER = 0x002,
	NPC = 0x004,
	PROJECTILE = 0x008,
	TERRAIN = 0x0010,
	ITEM = 0x0020,
	DOOR = 0x0040,
	DOOR_SENSOR = 0x0080,
	XP = 0x0100,
	PARTICLE = 0x0200,
	ALL = DEFAULT | PLAYER | NPC | PROJECTILE | TERRAIN | ITEM | DOOR | DOOR_SENSOR | XP | PARTICLE
};

class Entity
{
protected:
	std::map<Handler, std::vector<Component*> > m_components;

	void runComponents(Handler handler);
public:
	~Entity();

	sf::IntRect getBoundingBox();
	virtual sf::IntRect getAABB();

	virtual void step();
	virtual void update();
	virtual void render();

	virtual void beginContact(Entity *entity);
	virtual void endContact(Entity *entity);

	virtual int getCategory();
	virtual int getMask();

	virtual void Interact(Player *player);

	virtual bool isCollidable(Entity *entity);

	void addComponent(Component *component, Handler handler);
};

#endif