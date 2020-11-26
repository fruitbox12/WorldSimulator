#pragma once

#include "constants.h"
#include "commandinterpreter.h"
#include "actor.h"
#include "actorlevel.h"
#include "location.h"
#include "position.h"
#include "command.h"
#include "response.h"
#include <map>
#include <string>
#include <vector>
#include <list>
#include <map>

// The top level
// OOP Inheritance: World "IS A" ActorLevel
// OOP Composition: World "HAS A" CommandInterpreter (World IS NOT a CommandInterpreter)
class World : public ActorLevel {
	private:
		CommandInterpreter		commandInterpreter;
		bool					valid;

		// OOP: Abstraction / Data hidding (the World only knows what it needs to know)
		// OOP: Composition: the World HAS A Level
		static int									actorId;
		static std::map<std::string, ActorLevel*>	registry;

		// Helper functions
		DIRECTIONS getDirection(std::string direction);

	public:
		World();
		~World();

		// Getters
		bool isValid();
		std::map<std::string, ActorLevel*> getRegistry();

		bool create(std::string filePath, std::string fileName, std::vector<std::string> &messages);
		Command* findCommand(std::string command);
		Response execute(std::string command, Actor *actor);

		Actor* findActor(std::string name);
		bool addActor(Actor* actor);
		bool addActor(Actor* actor, int row, int col);
		
		static int genActorId();
		static bool addRegistry(Actor* actor, ActorLevel* actorLevel);
};
