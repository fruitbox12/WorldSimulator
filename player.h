#pragma once

#include "actor.h"
#include "level.h"
#include <string>
#include <stdlib.h>				// srand, rand
#include <time.h>				// time
using namespace std;

class Player : public Actor {
	private:
		Level	&level;
		int		row;
		int		col;

	public:
		Player(int id, string name, string description);
		~Player();

		Level& getLevel();
		int getRow();
		int getCol();

		void move(Level &level, int row, int col);
};

