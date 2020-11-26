#pragma once

#include "argument.h"
#include <string>
using namespace std;

class WittyArgument : public Argument {
	private:
		string		response;

	public:
		WittyArgument();
		WittyArgument(string response);
		
		// Destructor
		virtual ~WittyArgument();

		// Getters
		string getResponse();

		// Setters
		void setResponse(string response);
};

