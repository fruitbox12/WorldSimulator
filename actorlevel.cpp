#include "actorlevel.h"

ActorLevel::ActorLevel() {
}

ActorLevel::ActorLevel(int id, string name, string description, int rows, int cols, bool moveable) : Actor(id, name, description, ACTOR_TYPES::ACTOR_LEVEL, moveable), Level(rows, cols) {
}

ActorLevel::~ActorLevel() {
}

Level* ActorLevel::getLevel() {
	return Level::getLevel();
}

Actor* ActorLevel::findActor(string name) {
	return Level::findActor(name);
}

bool ActorLevel::addActor(Actor* actor) {
	return Level::addActor(actor);
}

bool ActorLevel::addActor(Actor* actor, int row, int col) {
	return Level::addActor(actor, row, col);
}
