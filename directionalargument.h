#pragma once

#include "argument.h"

class DirectionalArgument : public Argument {
	private:
		int			rowOffset;
		int			colOffset;

	public:
		DirectionalArgument();
		DirectionalArgument(DIRECTIONS direction);
		DirectionalArgument(int rowOffset, int colOffset, DIRECTIONS direction);
		
		// Destructor
		virtual ~DirectionalArgument();

		// Getters
		int getRowOffset();
		int getColOffset();

		// Setters
		void setRowOffset(int offset);
		void setColOffset(int offset);

		void overrideOffset(int offset);
};

