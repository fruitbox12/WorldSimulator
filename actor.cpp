#include "actor.h"

// Forward declaration used in header instead of using using #include "location.h"
// to prevent circular dependency ("include hell").
// If you need to reference the Location class or its members in the source file
// the compiler requires the complete inclusion of Location.
#include "location.h"

Actor::Actor() {
	id			= 0;
	name		= "";
	description = "";
	type		= ACTOR_TYPES::NOT_AN_ACTOR;
	movable		= false;
	location	= new Location();
	character   = new Character();
}

Actor::Actor(int id, string name, string description, ACTOR_TYPES type, bool movable) {
	this->id			= id;
	this->name			= name;
	this->description	= description;
	this->type			= type;
	this->movable		= movable;
	this->location		= new Location();
	character			= new Character();
}

Actor::~Actor() {
}

int Actor::getId() const {
	return id;
}

string Actor::getName() const {
	return name;
}

string Actor::getDescription() const {
	return description;
}

ACTOR_TYPES Actor::getType() const {
	return type;
}

string Actor::getTypeName() const {
	return ACTOR_TYPE_NAMES[static_cast<int>(type)];
}

bool Actor::isMovable() const {
	return movable;
}

Location* Actor::getLocation() {
	// Caller must check for nullptr before using!
	return location;
}

Character* Actor::getCharacter() {
	return character;
}

bool Actor::isValid() const {
	return id > 0 && name.length() > 0 && description.length() > 0 && type != ACTOR_TYPES::NOT_AN_ACTOR && location->isValid();
}

void Actor::setId(int id) {
	this->id = id;
}

void Actor::setName(string name) {
	this->name = name;
}

void Actor::setDescription(string description) {
	this->description = description;
}

void Actor::setType(ACTOR_TYPES type) {
	this->type = type;
}

void Actor::setMoveable(bool moveable) {
	this->movable = movable;
}

void Actor::setLocation(Location* location) {
	delete this->location;
	this->location = location;
}

void Actor::setCharacter(Character* character) {
	delete this->character;
	this->character = character;
}
