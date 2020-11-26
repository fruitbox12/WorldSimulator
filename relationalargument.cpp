#include "relationalargument.h"

RelationalArgument::RelationalArgument(DIRECTIONS direction) : Argument(direction) {
}

RelationalArgument::~RelationalArgument() {
}

// Copy constructor
RelationalArgument::RelationalArgument(const RelationalArgument &other) : Argument(other) {
	
	// FOR TEST PURPOSES ONLY
	//cout << "RelationalArgument::RelationalArgument copy constructor(): RelationalArgument object " << &other << " copied: " << this << endl;
}

// Copy assignment operator
RelationalArgument& RelationalArgument::operator =(const RelationalArgument &other) {
	Argument::operator=(other);

	// FOR TEST PURPOSES ONLY
	//cout << "RelationalArgument::RelationalArgument copy assignment operator: RelationalArgument object " << &other << " copied: " << this << endl;

	return *this;
}
