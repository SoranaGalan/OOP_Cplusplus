#pragma once
#include "Aircraft.h"
class Helicopter : public Aircraft
{
private:
	bool isPrivate;

public:
	Helicopter();
	~Helicopter();

	std::string toString();
};

