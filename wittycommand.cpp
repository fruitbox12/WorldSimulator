#include "wittycommand.h"

WittyCommand::WittyCommand(Command::COMMAND_TYPE type, string command, Command::ARGUMENT_TYPE argumentType, string response, string negativeResponse, string description) : Command(type, command, argumentType, response, negativeResponse, description) {
	init();
}

WittyCommand::~WittyCommand() {
}

void WittyCommand::init() {
	// Witty arguments
	insertArgument("to hell", new WittyArgument("You first!"));
}

