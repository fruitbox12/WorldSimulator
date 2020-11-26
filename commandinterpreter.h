#pragma once

#include "dictionary.h"
#include "command.h"
#include "response.h"
#include "actor.h"
#include <string>
using namespace std;

class CommandInterpreter {
	private:
		// OOP: Composition: the Command Interpreter "HAS A" Dictionary
		// Automatic object
		Dictionary	dictionary;

	public:
		CommandInterpreter();
		~CommandInterpreter();

		Command* findCommand(string command);
		Response execute(string command, Actor *actor);
		Response execute(string command, string argument, Actor *actor);
};
