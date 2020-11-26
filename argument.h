#pragma once

#include "constants.h"
#include <string>
using namespace std;

// A "wrapper" class
class Argument {
	private:
		DIRECTIONS	direction;
		bool		found;

	public:
		Argument();
		Argument(DIRECTIONS direction);
		
		virtual ~Argument();

		// Copy constructor and copy assignment operator
		Argument(const Argument &other);
		Argument &Argument::operator =(const Argument &other);

		// Getters
		DIRECTIONS getDirection();
		bool wasFound();

		// Setters
		void setDirection(DIRECTIONS direction);
		void setFound(bool found);
};
