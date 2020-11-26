#pragma once

#include "argument.h"
#include <string>
using namespace std;

// A "wrapper" class
class RelationalArgument : public Argument {
	private:

	public:
		RelationalArgument(DIRECTIONS direction);
		
		// Copy constructor and copy assignment operator
		RelationalArgument(const RelationalArgument &other);
		RelationalArgument &RelationalArgument::operator =(const RelationalArgument &other);

		// Destructor
		virtual ~RelationalArgument();
};
