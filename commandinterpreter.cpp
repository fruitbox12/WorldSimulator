#include "commandinterpreter.h"

CommandInterpreter::CommandInterpreter() {
}

CommandInterpreter::~CommandInterpreter() {
}

Command* CommandInterpreter::findCommand(string command) {
	return dictionary.findCommand(command);
}

Response CommandInterpreter::execute(string command, Actor *actor) {
	Response response;

	// Try to find the command. If command is not found 
	Command *commandFunction = findCommand(command);

	// Check if this is a real Command
	if (commandFunction->isCommand()) {
		// Execute the Command
		response = commandFunction->execute(actor);
	}
	else {
		response.setStatus(Response::STATUS::INVALID_COMMAND);
		response.setNegativeResponse(INVALID_COMMAND);
	}
	
	return response;
}

Response CommandInterpreter::execute(string command, string argument, Actor *actor) {
	Response response;

	// Try to find the command. If command is not found 
	Command *commandFunction = findCommand(command);

	// Check if this is a real Command
	if (commandFunction->isCommand()) {
		// Execute the Command
		response = commandFunction->execute(argument, actor);
	}
	else {
		response.setStatus(Response::STATUS::INVALID_COMMAND);
		response.setNegativeResponse(INVALID_COMMAND);
	}

	return response;
}
