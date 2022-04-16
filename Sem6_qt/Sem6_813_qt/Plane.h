#pragma once
#include "Aircraft.h"

class Plane :Aircraft
{
private:
	bool isPrivate;
	bool monoplane;
public:
	Plane();
	~Plane();
};

