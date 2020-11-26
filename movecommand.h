#pragma once

#include "command.h"
#include "argument.h"
#include "directionalargument.h"
#include "relationalargument.h"
#include "wittyargument.h"
#include "location.h"
#include "tools.h"
#include "response.h"
#include "actor.h"
#include <map>
#include <string>
using namespace std;

class MoveCommand : public Command {
	private:
		
		// Helper functions
		void init();
		Location getRelativePosition(Actor *actor, string argument);

	public:
		MoveCommand(Command::COMMAND_TYPE type, string command, Command::ARGUMENT_TYPE argumentType, string response, string negativeResponse, string description);
		
		// Destructor
		virtual ~MoveCommand();

		Response execute(Actor *actor);
		Response execute(string argument, Actor *actor);
};
