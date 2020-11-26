#pragma once

#include "constants.h"
#include "argument.h"
#include "actor.h"
#include "level.h"
#include "position.h"
#include <string>
using namespace std;

// A "wrapper" class
class Location {
	private:
		std::string		name;
		//Actor			*parentActor;
		Level			*level;
		Position		*position;
		DIRECTIONS		direction;

	public:
		Location();
		Location(std::string name, Level* level, Position* position, DIRECTIONS direction);
		~Location();

		// Copy constructor and copy assignment operator
		Location(const Location *other);
		Location *Location::operator =(const Location *other);

		// Getters
		std::string getName();
		//Actor* getParentActor();
		string getParentActorName();
		Level* getLevel();
		Position* getPosition();
		DIRECTIONS getDirection();
		bool isValid();

		// Setters
		void setName(std::string name);
		//void setParentActor(Actor *parentActor);
		void setLevel(Level *level);
		void setPosition(Position *position);
		void setDirection(DIRECTIONS direction);
};
