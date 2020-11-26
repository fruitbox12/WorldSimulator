#include "response.h"

Response::Response() {
	status			 = STATUS::NONE;
	response		 = "";
	negativeResponse = "";
}

Response::~Response() {
}

Response::STATUS Response::getStatus() {
	return status;
}

string Response::getResponse() {
	return response;
}

string Response::getNegativeResponse() {
	return negativeResponse;
}

void Response::setStatus(STATUS status) {

}

void Response::setResponse(string response) {
	this->response = response;
}

void Response::setNegativeResponse(string response) {
	this->negativeResponse = response;
}
