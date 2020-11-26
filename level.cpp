#include "level.h"

Level::Level() {
	rows			= 0;
	cols			= 0;
	numberOfActors	= 0;
}

Level::Level(int rows, int cols) {
	this->rows		= rows;
	this->cols		= cols;
	numberOfActors	= 0;
}

Level::~Level() {
	// MUST DELETE THE LEVEL GRID AND ITS CONTENTS
}

int Level::getRows() const {
	return rows;
}

int Level::getCols() const {
	return cols;
}

Level* Level::getLevel() {
	return this;
}

bool Level::isValid() const {
	return rows > 0 && cols > 0;
}

void Level::setRows(int rows) {
	this->rows = rows;
}

void Level::setCols(int cols) {
	this->cols = cols;
}

Actor* Level::findActor(std::string name) {
	Actor *actor = nullptr;

	for (std::map<Actor*, Position*>::const_iterator iterator = actorIndex.begin(); iterator != actorIndex.end(); iterator++) {
		if (iterator->first->getName() == name) {
			actor = iterator->first;
			break;
		}
	}

	if (actor == nullptr) {
		// Return a non-Actor instead of a nullptr
		actor = new Actor();
	}

	return actor;
}

bool Level::addActor(Actor* actor) {
	bool added = false;

	if (numberOfActors < rows * cols) {
		while (!added) {
			std::uniform_int_distribution<int> randomRow{ 1, static_cast<int>(rows) };
			int row = randomRow(mersenneTwisterEngine);
			std::uniform_int_distribution<int> randomCol{ 1, static_cast<int>(cols) };
			int col = randomCol(mersenneTwisterEngine);

			if (level.at(row - 1).at(col - 1) == nullptr) {
				level.at(row - 1).at(col - 1) = actor;
				numberOfActors++;

				// Add the Actor to the index
				Position *position = new Position();
				position->setRow(row);
				position->setCol(col);

				std::pair< Actor*, Position*> pair(actor, position);
				actorIndex.insert(pair);

				added = true;
			}
		}
	}

	return added;
}

bool Level::addActor(Actor* actor, int row, int col) {
	bool added = false;

	// Validate row & col are within the Level
	if (row >= 0 && row < LEVEL_ROWS && col >= 0 && col < LEVEL_COLS) {
		// Validate the Level is not full
		if (numberOfActors < LEVEL_ROWS * LEVEL_COLS) {
			// Validate the specified location is not occupied
			if (level.at(row - 1).at(col - 1) == nullptr) {
				level.at(row - 1).at(col - 1) = actor;
				numberOfActors++;

				// Add the Actor to the index
				Position *position = new Position();
				position->setRow(row);
				position->setCol(col);

				std::pair< Actor*, Position*> pair(actor, position);
				actorIndex.insert(pair);

				added = true;
			}
		}
	}

	return added;
}

bool Level::move(Actor* actor, DIRECTIONS direction) {
	
	return;
}

