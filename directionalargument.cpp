#include "directionalargument.h"

DirectionalArgument::DirectionalArgument() {
	this->rowOffset = 0;
	this->colOffset = 0;
}

DirectionalArgument::DirectionalArgument(DIRECTIONS direction) : Argument(direction) {
	this->rowOffset = 0;
	this->colOffset = 0;
}

DirectionalArgument::DirectionalArgument(int rowOffset, int colOffset, DIRECTIONS direction) : Argument(direction) {
	this->rowOffset = rowOffset;
	this->colOffset = colOffset;
}

DirectionalArgument::~DirectionalArgument() {
}

int DirectionalArgument::getRowOffset() {
	return rowOffset;
}

int DirectionalArgument::getColOffset() {
	return colOffset;
}

void DirectionalArgument::setRowOffset(int offset) {
	rowOffset = offset;
}

void DirectionalArgument::setColOffset(int offset) {
	colOffset = offset;
}

void DirectionalArgument::overrideOffset(int offset) {
	switch (static_cast<int>(getDirection())) {
		case static_cast<int>(DIRECTIONS::NORTH) :
		case static_cast<int>(DIRECTIONS::SOUTH) : {
			rowOffset = rowOffset * offset;
			break;
		}
		case static_cast<int>(DIRECTIONS::EAST) :
		case static_cast<int>(DIRECTIONS::WEST) : {
			colOffset = colOffset * offset;
			break;
		}
	}
}
