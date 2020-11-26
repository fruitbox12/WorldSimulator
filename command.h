#pragma once

#include "constants.h"
#include "actor.h"
#include "argument.h"
#include "response.h"
#include "tools.h"
#include <string>
#include <map>
using namespace std;

class Command {
	public:
		enum class COMMAND_TYPE {
			NONE,
			EXIT,
			HELP,
			LOCATION,
			MOVE,
			MOVE_DIRECTIONAL,
			MOVE_RELATIONAL,
			TURN,
			TURN_DIRECTIONAL,
			TURN_RELATIONAL,
			WITTY,
			COUNT
		};

		enum class ARGUMENT_TYPE {
			NONE,
			OPTIONAL_ARGUMENT,
			REQUIRED_ARGUMENT,
			COUNT
		};

		Command();
		Command(COMMAND_TYPE type, string command);
		Command(COMMAND_TYPE type, string command, string description);
		Command(COMMAND_TYPE type, string command, ARGUMENT_TYPE argumentType, string response, string negativeResponse, string description);

		// Destructor
		virtual ~Command();

		// Getters
		bool isCommand();
		COMMAND_TYPE getType();
		string getCommand();
		ARGUMENT_TYPE getArgumentType();
		string getDirectionName(DIRECTIONS direction);
		string getResponse();
		string getNegativeResponse();
		string getDescription();
		Argument* getArgument(string argument);

		// Setters
		bool insertArgument(string name, Argument *argument);

		// Override in child classes or these do-nothing implementations may run.
		// Cannot use pure virtual definitions (e.g., virtual void init() = 0;); 
		// The Command class becomes an abstract class, cannot instantiate
		// abstract classes.
		virtual void init();
		virtual Response execute(Actor *actor);
		virtual Response execute(string argument, Actor *actor);

	private:
		COMMAND_TYPE	type;
		string			command;
		ARGUMENT_TYPE	argumentType;
		string			response;
		string			negativeResponse;
		string			description;

		// Store Argument pointers to avoid "object slicing"
		map<string, Argument*>	arguments;
};
