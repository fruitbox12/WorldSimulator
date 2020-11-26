#pragma once

#include "constants.h"
#include <string>

class Character {
	private:
		std::string			name;
		std::string			description;
		CHARACTER_TYPES		type;
		int					power;
		int					lives;

	public:
		Character();
		Character(std::string name, std::string description, CHARACTER_TYPES type, int power, int lives);
		~Character();

		// Getters
		std::string		getName() const;
		std::string		getDescription() const;
		int				getPower() const;
		int				getLives() const;
		bool			isValid() const;

		// Setters
		void			setName(std::string name);
		void			setDescription(std::string description);
		void			setPower(int power);
		void			setLives(int lives);
};
