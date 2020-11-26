#pragma once

#include "constants.h"

// A "wrapper" class
class Position {
	private:
		int	row;
		int	col;

	public:
		Position();
		Position(int row, int col);
		~Position();

		// Getters
		int getRow();
		int getCol();
		bool isValid();

		// Setters
		void setRow(int row);
		void setCol(int col);
		void clear();
};
