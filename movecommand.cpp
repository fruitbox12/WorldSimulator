#include "movecommand.h"

MoveCommand::MoveCommand(Command::COMMAND_TYPE type, string command, Command::ARGUMENT_TYPE argumentType, string response, string negativeResponse, string description) : Command(type, command, argumentType, response, negativeResponse, description) {
	init();
}

MoveCommand::~MoveCommand() {
}

void MoveCommand::init() {
	// Directional arguments
	insertArgument("north", new DirectionalArgument(-1, 0, DIRECTIONS::NORTH));
	insertArgument("n", new DirectionalArgument(-1, 0, DIRECTIONS::NORTH));
	insertArgument("south", new DirectionalArgument(1, 0, DIRECTIONS::SOUTH));
	insertArgument("s", new DirectionalArgument(1, 0, DIRECTIONS::SOUTH));
	insertArgument("east", new DirectionalArgument(0, 1, DIRECTIONS::EAST));
	insertArgument("e", new DirectionalArgument(0, 1, DIRECTIONS::EAST));
	insertArgument("west", new DirectionalArgument(0, -1, DIRECTIONS::WEST));
	insertArgument("w", new DirectionalArgument(0, -1, DIRECTIONS::WEST));
	insertArgument("northeast", new DirectionalArgument(-1, 1, DIRECTIONS::NORTHEAST));
	insertArgument("ne", new DirectionalArgument(-1, 1, DIRECTIONS::NORTHEAST));
	insertArgument("northwest", new DirectionalArgument(-1, -1, DIRECTIONS::NORTHWEST));
	insertArgument("nw", new DirectionalArgument(-1, -1, DIRECTIONS::NORTHWEST));
	insertArgument("southeast", new DirectionalArgument(1, 1, DIRECTIONS::SOUTHEAST));
	insertArgument("se", new DirectionalArgument(1, 1, DIRECTIONS::SOUTHEAST));
	insertArgument("southwest", new DirectionalArgument(1, -1, DIRECTIONS::SOUTHWEST));
	insertArgument("sw", new DirectionalArgument(1, -1, DIRECTIONS::SOUTHWEST));

	// Relational arguments
	insertArgument("up", new RelationalArgument(DIRECTIONS::FORWARD));
	insertArgument("u", new RelationalArgument(DIRECTIONS::FORWARD));
	insertArgument("down", new RelationalArgument(DIRECTIONS::BACKWARD));
	insertArgument("d", new RelationalArgument(DIRECTIONS::BACKWARD));
	insertArgument("slightleft", new RelationalArgument(DIRECTIONS::SLIGHT_LEFT));
	insertArgument("slight left", new RelationalArgument(DIRECTIONS::SLIGHT_LEFT));
	insertArgument("sl", new RelationalArgument(DIRECTIONS::SLIGHT_LEFT));
	insertArgument("left", new RelationalArgument(DIRECTIONS::LEFT));
	insertArgument("l", new RelationalArgument(DIRECTIONS::LEFT));
	insertArgument("slightright", new RelationalArgument(DIRECTIONS::SLIGHT_RIGHT));
	insertArgument("slight right", new RelationalArgument(DIRECTIONS::SLIGHT_RIGHT));
	insertArgument("sr", new RelationalArgument(DIRECTIONS::SLIGHT_RIGHT));
	insertArgument("right", new RelationalArgument(DIRECTIONS::RIGHT));
	insertArgument("r", new RelationalArgument(DIRECTIONS::RIGHT));

	// Witty arguments
	insertArgument("to hell", new WittyArgument("You first!"));
}

Response MoveCommand::execute(Actor *actor) {
	Response response;

	bool moved = false;
	int newRow = 0;
	int newCol = 0;

	ARGUMENT_TYPE argumentType = getArgumentType();

	if (argumentType == Command::ARGUMENT_TYPE::NONE || 
		argumentType == Command::ARGUMENT_TYPE::OPTIONAL_ARGUMENT) {

		// Treat the command as its own argument
		string command = getCommand();
		Argument *parsedArgument = getArgument(command);

		if (parsedArgument->getDirection() == DIRECTIONS::NONE) {

		}


	}
	else if (argumentType == Command::ARGUMENT_TYPE::REQUIRED_ARGUMENT) {
		// Invalid argument
		response.setStatus(Response::STATUS::INVALID_ARGUMENT);
		response.setNegativeResponse(getCommand() + " where?");
	}

	return response;
}

Response MoveCommand::execute(string argument, Actor *actor) {
	Response response;

	// Get the Actor's current location
	Location *location = actor->getLocation();

	// Check the argument type
	if (getArgumentType() != ARGUMENT_TYPE::NONE) {
		// Get the argument
		Argument *argumentPtr = getArgument(argument);

		if (argumentPtr->wasFound()) {
			// Try to move the Actor to its new location



		}
		else {
			// Invalid argument
			response.setStatus(Response::STATUS::INVALID_ARGUMENT);
			response.setNegativeResponse(getCommand() + " where?");
		}
	}
	else {
		// We should never be here for a command with no argument allowed (ARGUMENT_TYPE::NONE).
		// Invalid argument
		response.setStatus(Response::STATUS::INVALID_ARGUMENT);
		response.setNegativeResponse(getCommand() + " where?");
	}

	return response;
}
