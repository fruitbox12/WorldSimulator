#include "player.h"

Player::Player(int id, string name, string description) : Actor(id, name, description, ACTOR_TYPES::ACTOR, true), level(level) {
	row = NOT_ON_LEVEL;
	col = NOT_ON_LEVEL;

	// Initialize random seed (only once per program run)
	srand(time(NULL));
}

Player::~Player() {
}

Level& Player::getLevel() {
	return level;
}

int Player::getRow() {
	return row;
}

int Player::getCol() {
	return col;
}

void Player::move(Level &level, int row, int col) {
	this->level = level;
	this->row	= row;
	this->col	= col;
}
