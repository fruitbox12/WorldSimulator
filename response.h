#pragma once

#include <string>
using namespace std;

// A "wrapper" class
class Response {
	public:
		Response();
		~Response();

		enum class STATUS {
			NONE,
			EXECUTED,
			INVALID_COMMAND,
			INVALID_ARGUMENT,
			COUNT
		};

		// Getters
		STATUS getStatus();
		string getResponse();
		string getNegativeResponse();

		// Setters
		void setStatus(STATUS status);
		void setResponse(string response);
		void setNegativeResponse(string response);

	private:
		STATUS	status;
		string	response;
		string	negativeResponse;
};

