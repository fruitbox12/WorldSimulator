#include "command.h"

Command::Command() {
	type			 = COMMAND_TYPE::NONE;
	command			 = NOT_A_COMMAND;
	argumentType	 = ARGUMENT_TYPE::NONE;
	response		 = NOT_A_COMMAND;
	negativeResponse = NOT_A_COMMAND;
	description		 = NOT_A_COMMAND;
}

Command::Command(COMMAND_TYPE type, string command) {
	this->type				= type;
	this->command			= command;
	this->argumentType		= ARGUMENT_TYPE::NONE;
	this->response			= NOT_A_COMMAND;
	this->negativeResponse	= NOT_A_COMMAND;
	this->description		= NOT_A_COMMAND;
}

Command::Command(COMMAND_TYPE type, string command, string description) {
	this->type				= type;
	this->command			= command;
	this->argumentType		= ARGUMENT_TYPE::NONE;
	this->response			= NOT_A_COMMAND;
	this->negativeResponse	= NOT_A_COMMAND;
	this->description		= description;
}

Command::Command(COMMAND_TYPE type, string command, ARGUMENT_TYPE argumentType, string response, string negativeResponse, string description) {
	this->type				= type;
	this->command			= command;
	this->argumentType		= argumentType;
	this->response			= response;
	this->negativeResponse	= negativeResponse;
	this->description		= description;
}

Command::~Command() {
}

bool Command::isCommand() {
	return type != COMMAND_TYPE::NONE;
}

Command::COMMAND_TYPE Command::getType() {
	return type;
}

string Command::getCommand() {
	return command;
}

Command::ARGUMENT_TYPE Command::getArgumentType() {
	return argumentType;
}

string Command::getDirectionName(DIRECTIONS direction) {
	return DIRECTION_NAMES[static_cast<int>(direction)];
}

string Command::getResponse() {
	return response;
}

string Command::getNegativeResponse() {
	return negativeResponse;
}

string Command::getDescription() {
	return description;
}

Argument* Command::getArgument(string argument) {
	Argument *parsedArgument = new Argument();

	map<string, Argument*>::const_iterator iterator;

	iterator = arguments.find(Tools::toLower(argument));

	// Check if the argument was found
	if (iterator != arguments.end()) {
		parsedArgument = iterator->second;
		parsedArgument->setFound(true);
	}

	return parsedArgument;
}

void Command::init() {
}

bool Command::insertArgument(string name, Argument *argument) {
	bool inserted = false;

	if (arguments.insert(make_pair(name, argument)).second) {
		inserted = true;
	}

	return inserted;
}

Response Command::execute(Actor *actor) {
	Response response;
	return response;
}

Response Command::execute(string argument, Actor *actor) {
	Response response;
	return response;
}
