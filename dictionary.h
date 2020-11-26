#pragma once

#include "command.h"
#include "movecommand.h"
#include "tools.h"
#include <map>
using namespace std;

class Dictionary {
	private:
		// Store Command pointers to avoid "object slicing"
		map<string, Command*>	dictionary;

	public:
		Dictionary();
		~Dictionary();

		Command* findCommand(string command);
};
