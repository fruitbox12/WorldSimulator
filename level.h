#pragma once

#include "constants.h"
#include "actor.h"
#include "position.h"
#include <random>		// For std::random_device and std::mt19937
#include <map>
#include <string>
#include <vector>

// Best for performance to create it only once.
// C++11 std::mt19937 provides pseudo-random generator of 32-bit numbers with a state size of 19937 bits.
static std::mt19937 mersenneTwisterEngine{ std::random_device{}() };

class Level {
	private:
		std::vector<std::vector<Actor*>>	level;
		int									rows;
		int									cols;
		int									numberOfActors;
		std::map<Actor*, Position*>			actorIndex;

	public:
		Level();
		Level(int rows, int cols);
		~Level();

		// Getters
		int		getRows() const;
		int		getCols() const;
		Level*	getLevel();
		bool	isValid() const;

		// Setters
		void	setRows(int rows);
		void	setCols(int cols);
		
		Actor*	findActor(std::string name);

		// OOP: Function Overloading (same function name, DIFFERENT parameter lists)
		// Add Actor randomly
		bool	addActor(Actor* actor);
		// Add Actor at a specified location
		bool	addActor(Actor* actor, int row, int col);

		// PROTOTYPE
		bool move(Actor* actor, DIRECTIONS direction);
};
