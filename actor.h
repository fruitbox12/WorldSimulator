#pragma once

#include "constants.h"
#include "character.h"
#include <string>

// "Forward declaration". Alternate way of including Location class.
// Cannot use #include, Location already includes Actor, causes recursive including ("include hell").
// Must #include location.h in the Actor source file.
class Location;

class Actor {
	private:
		int				id;
		std::string		name;
		std::string		description;
		ACTOR_TYPES		type;
		bool			movable;
		Location*		location;

		// OOP Composition: Actor "HAS A" Character
		Character*		character;

	public:
		Actor();
		Actor(int id, string name, string description, ACTOR_TYPES type, bool movable);
		~Actor();

		// Getters
		int				getId() const;
		std::string		getName() const;
		std::string		getDescription() const;
		ACTOR_TYPES		getType() const;
		std::string		getTypeName() const;
		bool			isMovable() const;
		Location*		getLocation();
		Character*		getCharacter();
		bool			isValid() const;

		// Setters
		void setId(int id);
		void setName(string name);
		void setDescription(string description);
		void setType(ACTOR_TYPES type);
		void setMoveable(bool moveable);
		void setLocation(Location* location);
		void setCharacter(Character* character);
};
