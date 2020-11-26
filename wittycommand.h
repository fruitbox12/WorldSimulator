#pragma once

#include "command.h"
#include "argument.h"
#include "wittyargument.h"
#include "location.h"
#include "tools.h"
#include <map>
#include <string>
using namespace std;

class WittyCommand : public Command {
	private:
		// Automatic object
		map<string, Argument*>	arguments;

		// Helper functions
		void init();
		Location getRelativePosition(Actor *actor, string argument);

	public:
		WittyCommand(Command::COMMAND_TYPE type, string command, Command::ARGUMENT_TYPE argumentType, string response, string negativeResponse, string description);
		
		// Destructor
		virtual ~WittyCommand();
};
