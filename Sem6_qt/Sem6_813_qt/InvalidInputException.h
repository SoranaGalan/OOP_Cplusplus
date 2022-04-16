#pragma once
#include <exception>

class InvalidInputException : public std::exception
{
public:
	const char* what() const throw (){
		return "Invalid user input";
	}

	InvalidInputException();
	~InvalidInputException();
};

