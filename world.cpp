#include "world.h"

// Prevent error LNK2001 : unresolved external symbol "private: static int/map
int World::actorId = 0;
std::map<std::string, ActorLevel*> World::registry;

World::World() {
	valid = false;
}

World::~World() {
}

DIRECTIONS World::getDirection(std::string direction) {
	DIRECTIONS directionEnum = DIRECTIONS::NONE;
	direction = Tools::toUpper(direction);
	
	if (direction == "NORTH") {
		directionEnum = DIRECTIONS::NORTH;
	}
	else if (direction == "SOUTH") {
		directionEnum = DIRECTIONS::SOUTH;
	}
	else if (direction == "EAST") {
		directionEnum = DIRECTIONS::EAST;
	}
	else if (direction == "WEST") {
		directionEnum = DIRECTIONS::WEST;
	}
	else if (direction == "NORTHEAST") {
		directionEnum = DIRECTIONS::NORTHEAST;
	}
	else if (direction == "NORTHWEST") {
		directionEnum = DIRECTIONS::NORTHWEST;
	}
	else if (direction == "SOUTHEAST") {
		directionEnum = DIRECTIONS::SOUTHEAST;
	}
	else if (direction == "SOUTHWEST") {
		directionEnum = DIRECTIONS::SOUTHWEST;
	}
	else if (direction == "RELATIVE-DIRECTION") {
		directionEnum = DIRECTIONS::RELATIVE_DIRECTION;
	}
	else if (direction == "CURRENT-DIRECTION") {
		directionEnum = DIRECTIONS::CURRENT_DIRECTION;
	}
	else if (direction == "FORWARD") {
		directionEnum = DIRECTIONS::FORWARD;
	}
	else if (direction == "BACKWARD") {
		directionEnum = DIRECTIONS::BACKWARD;
	}
	else if (direction == "UP") {
		directionEnum = DIRECTIONS::UP;
	}
	else if (direction == "DOWN") {
		directionEnum = DIRECTIONS::DOWN;
	}
	else if (direction == "LEFT") {
		directionEnum = DIRECTIONS::LEFT;
	}
	else if (direction == "SLIGHT-LEFT") {
		directionEnum = DIRECTIONS::SLIGHT_LEFT;
	}
	else if (direction == "SHARP-LEFT") {
		directionEnum = DIRECTIONS::SHARP_LEFT;
	}
	else if (direction == "AROUND-LEFT") {
		directionEnum = DIRECTIONS::AROUND_LEFT;
	}
	else if (direction == "RIGHT") {
		directionEnum = DIRECTIONS::RIGHT;
	}
	else if (direction == "SLIGHT-RIGHT") {
		directionEnum = DIRECTIONS::SLIGHT_RIGHT;
	}
	else if (direction == "SHARP-RIGHT") {
		directionEnum = DIRECTIONS::SHARP_RIGHT;
	}
	else if (direction == "AROUND-RIGHT") {
		directionEnum = DIRECTIONS::AROUND_RIGHT;
	}
	else if (direction == "IN-DIRECTION") {
		directionEnum = DIRECTIONS::IN_DIRECTION;
	}
	else if (direction == "OUT-DIRECTION") {
		directionEnum = DIRECTIONS::OUT_DIRECTION;
	}

	return directionEnum;
}

bool World::isValid() {
	return valid;
}

std::map<std::string, ActorLevel*> World::getRegistry() {
	return registry;
}

bool World::create(string filePath, string fileName, std::vector<std::string> &messages) {
	valid					= true;
	bool nameFound			= false;
	bool descriptionFound	= false;
	bool rowsFound			= false;
	bool colsFound			= false;
	bool moveableFound		= false;
	bool locationFound		= false;
	bool locationNameFound	= false;
	bool locationRowFound	= false;
	bool locationColFound	= false;
	bool directionFound		= false;

	std::vector<std::string>	errors;
	std::vector<std::string>	warnings;

	// Read the World XML file
	Tree<std::string, std::string>* rootTree = Tools::XMLParser(filePath, fileName, messages);

	if (rootTree->getSize() > 0) {
		// Set the World level's ID
		setId(genActorId());

		// Set the World level's Actor type
		setType(ACTOR_TYPES::ACTOR_LEVEL);

		// Get the root tree's nodes, if any
		std::vector<std::pair<std::string, std::string>> nodes = rootTree->getNodesInOrder();

		for (std::pair<std::string, std::string> pair : nodes) {
			if (pair.first == "name") {
				nameFound = true;

				std::string name = Tools::trim(pair.second);
				if (name.length() > 0) {
					setName(name);
				}
				else {
					errors.push_back("World: missing <name> tag text");
					valid = false;
				}
			}
			else if (pair.first == "description") {
				descriptionFound = true;

				std::string description = Tools::trim(pair.second);
				if (description.length() > 0) {
					setDescription(description);
				}
				else {
					errors.push_back("World: missing <description> tag text");
					valid = false;
				}
			}
			else if (pair.first == "rows") {
				rowsFound = true;

				try {
					setRows(stoi(Tools::trim(pair.second)));
				}
				catch (invalid_argument& e) {
					errors.push_back("World: invalid <rows> tag text");
					valid = false;
				}
			}
			else if (pair.first == "cols") {
				colsFound = true;

				try {
					setCols(stoi(Tools::trim(pair.second)));
				}
				catch (invalid_argument& e) {
					errors.push_back("World: invalid <cols> tag text");
					valid = false;
				}
			}
			else if (pair.first == "moveable") {
				moveableFound = true;

				std::string moveable = Tools::toLower(Tools::trim(pair.second));
				if (moveable.length() > 0) {
					if (moveable == "true") {
						setMoveable(true);
					}
					else if (moveable == "false") {
						setMoveable(false);
					}
					else {
						errors.push_back("World: invalid <moveable> tag text");
						valid = false;
					}
				}
				else {
					errors.push_back("World: missing <moveable> tag text");
					valid = false;
				}
			}
			else {
				errors.push_back("World: invalid tag found: " + pair.first);
				valid = false;
			}
		}

		// Check for missing World tags
		if (!nameFound) {
			errors.push_back("World: missing <name> tag");
			valid = false;
		}
		if (!descriptionFound) {
			errors.push_back("World: missing <description> tag");
			valid = false;
		}
		if (!rowsFound) {
			errors.push_back("World: missing <rows> tag");
			valid = false;
		}
		if (!colsFound) {
			errors.push_back("World: missing <cols> tag");
			valid = false;
		}
		if (!moveableFound) {
			errors.push_back("World: missing <moveable> tag");
			valid = false;
		}

		// Reset node indicators for the Actor-Level(s)
		nameFound			= false;
		descriptionFound	= false;
		rowsFound			= false;
		colsFound			= false;
		moveableFound		= false;

		// Create the World's Location (itself)
		setLocation(new Location(getName(), getLevel(), new Position(0,0), DIRECTIONS::HERE));

		// Get the root tree's Actor-Level subtrees
		if (rootTree->getSubtreeSize() > 0) {
			std::vector<Tree<std::string, std::string>*> actorLevelTrees = rootTree->getTreesInOrder();

			for (Tree<std::string, std::string>* actorLevelTree : actorLevelTrees) {
				ActorLevel* actorLevel = new ActorLevel();
				actorLevel->setId(genActorId());

				// Set the Actor-Level tree's Actor type
				actorLevel->setType(ACTOR_TYPES::ACTOR_LEVEL);

				// Get the Actor-Level subtree's nodes, if any
				std::vector<std::pair<std::string, std::string>> nodes = actorLevelTree->getNodesInOrder();

				for (std::pair<std::string, std::string> pair : nodes) {
					if (pair.first == "name") {
						nameFound = true;

						std::string name = Tools::trim(pair.second);
						if (name.length() > 0) {
							actorLevel->setName(name);
						}
						else {
							errors.push_back("Actor-Level: missing <name> tag text");
							valid = false;
						}
					}
					else if (pair.first == "description") {
						descriptionFound = true;

						std::string description = Tools::trim(pair.second);
						if (description.length() > 0) {
							actorLevel->setDescription(description);
						}
						else {
							errors.push_back("Actor-Level: missing <description> tag text");
							valid = false;
						}
					}
					else if (pair.first == "rows") {
						rowsFound = true;

						try {
							actorLevel->setRows(stoi(Tools::trim(pair.second)));
						}
						catch (invalid_argument& e) {
							errors.push_back("Actor-Level: invalid <rows> tag text");
							valid = false;
						}
					}
					else if (pair.first == "cols") {
						colsFound = true;

						try {
							actorLevel->setCols(stoi(Tools::trim(pair.second)));
						}
						catch (invalid_argument& e) {
							errors.push_back("Actor-Level: invalid <cols> tag text");
							valid = false;
						}
					}
					else if (pair.first == "moveable") {
						moveableFound = true;

						std::string moveable = Tools::toLower(Tools::trim(pair.second));
						if (moveable.length() > 0) {
							if (moveable == "true") {
								actorLevel->setMoveable(true);
							}
							else if (moveable == "false") {
								actorLevel->setMoveable(false);
							}
							else {
								errors.push_back("Actor-Level: invalid <moveable> tag text");
								valid = false;
							}
						}
						else {
							errors.push_back("Actor-Level: missing <moveable> tag text");
							valid = false;
						}
					}
					else {
						errors.push_back("Actor-Level: invalid tag found: " + pair.first);
						valid = false;
					}
				}

				// Check for missing Actor-Level tags
				if (!nameFound) {
					errors.push_back("Actor-Level: missing <name> tag");
					valid = false;
				}
				if (!descriptionFound) {
					errors.push_back("Actor-Level: missing <description> tag");
					valid = false;
				}
				if (!rowsFound) {
					errors.push_back("Actor-Level: missing <rows> tag");
					valid = false;
				}
				if (!colsFound) {
					errors.push_back("Actor-Level: missing <cols> tag");
					valid = false;
				}
				if (!moveableFound) {
					errors.push_back("Actor-Level: missing <moveable> tag");
					valid = false;
				}

				// Get the Actor-Level Location subtree, if any. There should be exactly one.
				std::vector<SubTree<std::string, std::string>*> subtrees = actorLevelTree->getSubtreesInOrder(actorLevelTree->getLevel() + 1);

				if (subtrees.size() > 0) {
					if (subtrees.size() == 1) {
						SubTree<std::string, std::string>* locationTree = subtrees.at(0);

						if (locationTree->getKey() == "location") {
							locationFound = true;

							Location* location = new Location();
							Position* position = new Position();

							// Get the Actor-Level Location subtree's nodes, if any
							std::vector<std::pair<std::string, std::string>> nodes = locationTree->getNodesInOrder();

							for (std::pair<std::string, std::string> pair : nodes) {
								if (pair.first == "name") {
									locationNameFound = true;

									std::string name = Tools::trim(pair.second);
									if (name.length() > 0) {
										location->setName(name);
									}
									else {
										errors.push_back("Location: missing <name> tag text");
										valid = false;
									}
								}
								else if (pair.first == "row") {
									locationRowFound = true;

									try {
										position->setRow(stoi(Tools::trim(pair.second)));
									}
									catch (invalid_argument& e) {
										errors.push_back("Location: invalid <row> tag text");
										valid = false;
									}
								}
								else if (pair.first == "col") {
									locationColFound = true;

									try {
										position->setCol(stoi(Tools::trim(pair.second)));
									}
									catch (invalid_argument& e) {
										errors.push_back("Location: invalid <col> tag text");
										valid = false;
									}
								}
								else if (pair.first == "direction") {
									directionFound = true;
									std::string direction = Tools::trim(pair.second);

									if (direction.length() > 0) {
										DIRECTIONS directionEnum = getDirection(direction);

										if (directionEnum != DIRECTIONS::NONE) {
											location->setDirection(directionEnum);
										}
										else {
											errors.push_back("Location: invalid <direction> tag text");
											valid = false;
										}
									}
									else {
										errors.push_back("Location: missing <direction> tag text");
										valid = false;
									}
								}
							}

							// Check for missing Location tags. Add the Position to the Location.
							if (!locationNameFound) {
								errors.push_back("Location: missing <name> tag");
								valid = false;
							}
							if (!locationRowFound) {
								errors.push_back("Location: missing <row> tag");
								valid = false;
							}
							if (!locationColFound) {
								errors.push_back("Location: missing <col> tag");
								valid = false;
							}
							if (!directionFound) {
								errors.push_back("Location: missing <direction> tag");
								valid = false;
							}

							if (valid) {
								// Add the Position to the Location and the Location to the Actor-Level
								location->setPosition(position);
								actorLevel->setLocation(location);
								// Register the Actor-Level. Its name must be unique.
								std::pair<std::map<std::string, ActorLevel*>::iterator, bool> pair = registry.insert(make_pair(actorLevel->getName(), actorLevel));

								if (!pair.second) {
									errors.push_back("Actor-Level: duplicate <actor-level> tag. Name must be unique");
									valid = false;
								}
							}
						}
						else {
							errors.push_back("Actor-Level: missing <location> tag. Unknown tag found");
							valid = false;
						}
					}
					else {
						errors.push_back("Actor-Level: duplicate <location> tag(s) found");
						valid = false;
					}
				}
				else {
					errors.push_back("Actor-Level: missing <location> tag");
					valid = false;
				}

				// Reset node indicators for the next Actor-Level
				nameFound			= false;
				descriptionFound	= false;
				rowsFound			= false;
				colsFound			= false;
				moveableFound		= false;
				locationFound		= false;
				locationNameFound	= false;
				locationRowFound	= false;
				locationColFound	= false;
				directionFound		= false;
			}
		}
	}

	if (errors.size() > 0) {
		messages.insert(messages.begin(), errors.begin(), errors.end());
	}

	if (warnings.size() > 0) {
		messages.insert(messages.end(), warnings.begin(), warnings.end());
	}

	return valid;
}

Command* World::findCommand(string command) {
	return commandInterpreter.findCommand(command);
}

Response World::execute(string command, Actor *actor) {
	Response response;
	bool executed = false;

	vector<string> words = Tools::wordSplit(command);

	if (words.size() == 1) {
		response = commandInterpreter.execute(words[0], actor);
	}
	else if (words.size() == 2) {
		response = commandInterpreter.execute(words[0], words[1], actor);
	}

	return response;
}

Actor* World::findActor(string name) {
	return ActorLevel::findActor(name);
}

int World::genActorId() {
	actorId++;
	return actorId;
}

bool World::addActor(Actor* actor) {
	return ActorLevel::addActor(actor);
}

bool World::addActor(Actor* actor, int row, int col) {
	return ActorLevel::addActor(actor, row, col);
}

bool World::addRegistry(Actor* actor, ActorLevel* actorLevel) {
	// WHAT HAPPENS WHEN THE ACTOR IS ALREADY ON THE REGISTRY
	// AND WE SIMPLY WANT TO UPDATE ITS LEVEL LOCATION???
	pair<map<string, ActorLevel*>::iterator, bool> pair = registry.emplace(make_pair(actor->getName(), actorLevel));

	return pair.second;
}
