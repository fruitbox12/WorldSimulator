#include "wittyargument.h"

WittyArgument::WittyArgument() {
	response = "";
}

WittyArgument::WittyArgument(string response) {
	this->response = response;
}

WittyArgument::~WittyArgument() {
}

string WittyArgument::getResponse() {
	return response;
}

void WittyArgument::setResponse(string response) {
	this->response = response;
}
