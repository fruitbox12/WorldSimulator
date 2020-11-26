#pragma once

#include "player.h"

// OOP Inheritance: HumanPlayer "IS A" Player
class HumanPlayer : public Player {
	private:

	public:
		HumanPlayer(int id, string name, string description);
		~HumanPlayer();
};
