#include "pch.h"
#include "Helicopter.h"


Helicopter::Helicopter()
{
	Aircraft::Aircraft();
}


Helicopter::~Helicopter()
{
}

std::string Helicopter::toString()
{
	return Aircraft::toString() + " isPrivate: " + std::to_string(this->isPrivate)+ "\n";
}
