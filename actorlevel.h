#pragma once

#include "actor.h"
#include "level.h"

// OOP: Multiple Inheritance: ActorLevel "IS A(N)" Actor and "IS A" Level
class ActorLevel : public Actor, public Level {
	private:

	public:
		ActorLevel();
		ActorLevel(int id, string name, string description, int rows, int cols, bool moveable);
		~ActorLevel();

		// Getters
		Level*	getLevel();

		Actor*	findActor(string name);

		// Add Actor randomly
		bool	addActor(Actor* actor);
		// Add Actor at a specified location
		bool	addActor(Actor* actor, int row, int col);
};
