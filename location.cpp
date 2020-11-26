#include "location.h"

Location::Location() {
	name		= "";
	//parentActor = new Actor();
	level		= nullptr;
	position	= new Position();
	direction	= DIRECTIONS::NONE;
}

Location::Location(std::string name, Level* level, Position* position, DIRECTIONS direction) {
	this->name		= name;
	this->level		= level;
	this->position	= position;
	this->direction = direction;
}

// Copy constructor
Location::Location(const Location *other) {
	name		= other->name;
	//parentActor = other->parentActor;
	level		= other->level;
	position	= other->position;
	direction	= other->direction;

	// FOR TEST PURPOSES ONLY
	//cout << "Location::Location copy constructor(): Location object " << other << " copied: " << this << endl;
}

// Copy assignment operator
Location* Location::operator =(const Location *other) {
	name		= other->name;
	//parentActor = other->parentActor;
	level		= other->level;
	position	= other->position;
	direction	= other->direction;

	return this;
}

Location::~Location() {
}

std::string Location::getName() {
	return name;
}

/*
Actor* Location::getParentActor() {
	return parentActor;
}
*/

/*
string Location::getParentActorName() {
	return parentActor->getName();
}
*/

Level* Location::getLevel() {
	if (level == nullptr) {
		level = new Level();
	}

	return level;
}

Position* Location::getPosition() {
	return position;
}

DIRECTIONS Location::getDirection() {
	return direction;
}

bool Location::isValid() {
	//return name.length() > 0 && parentActor->isValid() && level->isValid() && position->isValid() && direction != DIRECTIONS::NONE;
	return name.length() > 0 && level->isValid() && position->isValid() && direction != DIRECTIONS::NONE;
}

void Location::setName(std::string name) {
	this->name = name;
}

/*
void Location::setParentActor(Actor *parentActor) {
	delete this->parentActor;
	this->parentActor = parentActor;
}
*/

void Location::setLevel(Level *level) {
	if (level != nullptr) {
		delete this->level;
	}

	this->level = level;
}

void Location::setPosition(Position *position) {
	delete this->position;
	this->position = position;
}

void Location::setDirection(DIRECTIONS direction) {
	this->direction = direction;
}
