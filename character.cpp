#include "character.h"

Character::Character() {
	name			= "";
	description		= "";
	type			= CHARACTER_TYPES::NOT_A_CHARACTER;
	power			= 0;
	lives			= 0;
}

Character::Character(std::string name, std::string description, CHARACTER_TYPES type, int power, int lives) {
	this->name			= name;
	this->description	= description;
	this->type			= type;
	this->power			= power;
	this->lives			= lives;
}

Character::~Character() {
}

std::string Character::getName() const {
	return name;
}

std::string Character::getDescription() const {
	return description;
}

int Character::getPower() const {
	return power;
}

int Character::getLives() const {
	return lives;
}

bool Character::isValid() const {
	return name.length() > 0 && description.length() > 0 && power > 0;
}

void Character::setName(std::string name) {
	this->name = name;
}

void Character::setDescription(std::string description) {
	this->description = description;
}

void Character::setPower(int power) {
	this->power = power;
}

void Character::setLives(int lives) {
	this->lives = lives;
}
