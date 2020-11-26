#include "dictionary.h"

Dictionary::Dictionary() {
	// Move commands requiring a directional argument
	dictionary.insert(make_pair("go", new MoveCommand(Command::COMMAND_TYPE::MOVE, "go", Command::ARGUMENT_TYPE::REQUIRED_ARGUMENT, MOVE_RESPONSE, MOVE_NEGATIVE_RESPONSE, "Same as move. You must specify the direction")));
	dictionary.insert(make_pair("goto", new MoveCommand(Command::COMMAND_TYPE::MOVE, "goto", Command::ARGUMENT_TYPE::REQUIRED_ARGUMENT, MOVE_RESPONSE, MOVE_NEGATIVE_RESPONSE, "Same as move. You must specify the direction")));
	dictionary.insert(make_pair("gotta", new MoveCommand(Command::COMMAND_TYPE::MOVE, "gotta", Command::ARGUMENT_TYPE::REQUIRED_ARGUMENT, MOVE_RESPONSE, MOVE_NEGATIVE_RESPONSE, "Same as move. You must specify the direction")));
	dictionary.insert(make_pair("g", new MoveCommand(Command::COMMAND_TYPE::MOVE, "g", Command::ARGUMENT_TYPE::REQUIRED_ARGUMENT, MOVE_RESPONSE, MOVE_NEGATIVE_RESPONSE, "Short for go. Same as move. You must specify the direction")));
	dictionary.insert(make_pair("move", new MoveCommand(Command::COMMAND_TYPE::MOVE, "move", Command::ARGUMENT_TYPE::REQUIRED_ARGUMENT, MOVE_RESPONSE, MOVE_NEGATIVE_RESPONSE, "You must specify the direction")));
	dictionary.insert(make_pair("m", new MoveCommand(Command::COMMAND_TYPE::MOVE, "m", Command::ARGUMENT_TYPE::REQUIRED_ARGUMENT, MOVE_RESPONSE, MOVE_NEGATIVE_RESPONSE, "Short for move. You must specify the direction")));
	dictionary.insert(make_pair("turn", new MoveCommand(Command::COMMAND_TYPE::MOVE, "turn", Command::ARGUMENT_TYPE::REQUIRED_ARGUMENT, MOVE_RESPONSE, MOVE_NEGATIVE_RESPONSE, "Same as move. You must specify the direction")));
	dictionary.insert(make_pair("t", new MoveCommand(Command::COMMAND_TYPE::MOVE, "t", Command::ARGUMENT_TYPE::REQUIRED_ARGUMENT, MOVE_RESPONSE, MOVE_NEGATIVE_RESPONSE, "Short for turn. Same as move. You must specify the direction")));
	dictionary.insert(make_pair("walk", new MoveCommand(Command::COMMAND_TYPE::MOVE, "walk", Command::ARGUMENT_TYPE::REQUIRED_ARGUMENT, MOVE_RESPONSE, MOVE_NEGATIVE_RESPONSE, "Same as move. You must specify the direction")));
	dictionary.insert(make_pair("w", new MoveCommand(Command::COMMAND_TYPE::MOVE, "w", Command::ARGUMENT_TYPE::REQUIRED_ARGUMENT, MOVE_RESPONSE, MOVE_NEGATIVE_RESPONSE, "Short for walk. Same as move. You must specify the direction")));

	// Directional move commands
	dictionary.insert(make_pair("north", new MoveCommand(Command::COMMAND_TYPE::MOVE_DIRECTIONAL, "north", Command::ARGUMENT_TYPE::NONE, MOVE_RESPONSE, MOVE_NEGATIVE_RESPONSE, "You move to the north")));

	// Move commands relative to the Actor's current direction
	dictionary.insert(make_pair("up", new MoveCommand(Command::COMMAND_TYPE::MOVE_RELATIONAL, "up", Command::ARGUMENT_TYPE::OPTIONAL_ARGUMENT, MOVE_RESPONSE, MOVE_NEGATIVE_RESPONSE, "You move forward in your current direction")));
}

Dictionary::~Dictionary() {
}

Command* Dictionary::findCommand(string command) {
	// Create a "blank" Command
	Command *commandFunction = new Command();

	map<string, Command*>::const_iterator iterator;

	iterator = dictionary.find(Tools::toLower(command));

	if (iterator != dictionary.end()) {
		// Copy the command pointer
		commandFunction = iterator->second;
	}
		
	return commandFunction;

	// At end of funcion execution (executes }) all the local variables are automatically deleted
	// (command, commandFunction). However, the Command object the pointer commandFunction
	// "points to" IS NOT DELETED, the Command DESTRUCTOR is not invoked (called automatically).
	// The programmer is responsible for deleting all dynamic objects when they're no longer needed
	// by executing the DELETE command, and DEFINITELY BEFORE the app closes!
	// Otherwise, "memory leaks" occur that can only be clean-up
	// by rebooting the server!
 }
