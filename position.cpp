#include "position.h"

Position::Position() {
	row = NOT_A_POSITION;
	col = NOT_A_POSITION;
}

Position::Position(int row, int col) {
	this->row = row;
	this->col = col;
}

Position::~Position() {
}

int Position::getRow() {
	return row;
}
int Position::getCol() {
	return col;
}

bool Position::isValid() {
	return row != NOT_A_POSITION && col != NOT_A_POSITION;
}

void Position::setRow(int row) {
	this->row = row;
}

void Position::setCol(int col) {
	this->col = col;
}

void Position::clear() {
	row = NOT_A_POSITION;
	col = NOT_A_POSITION;
}
