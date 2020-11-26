#include "argument.h"

Argument::Argument() {
	this->direction = DIRECTIONS::NONE;
	this->found		= false;
}

Argument::Argument(DIRECTIONS direction) {
	this->direction = direction;
	this->found		= false;
}

Argument::~Argument() {
}

// Copy constructor
Argument::Argument(const Argument &other) {
	direction	= other.direction;
	found		= other.found;

	// FOR TEST PURPOSES ONLY
	//cout << "Argument::Argument copy constructor(): Argument object " << &other << " copied: " << this << endl;
}

// Copy assignment operator
Argument& Argument::operator =(const Argument &other) {
	direction	= other.direction;
	found		= other.found;

	// FOR TEST PURPOSES ONLY
	//cout << "Argument::Argument copy assignment operator: Argument object " << &other << " copied: " << this << endl;

	return *this;
}

DIRECTIONS Argument::getDirection() {
	return direction;
}

bool Argument::wasFound() {
	return found;
}

void Argument::setDirection(DIRECTIONS direction) {
	this->direction = direction;
}

void Argument::setFound(bool found) {
	this->found = found;
}
