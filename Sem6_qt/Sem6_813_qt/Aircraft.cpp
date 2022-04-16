#include "pch.h"
#include "Aircraft.h"

int Aircraft::nextID = 0;

Aircraft::Aircraft()
{
	this->identifier = nextID;
}


Aircraft::~Aircraft()
{
}

int Aircraft::getId()
{
	return this->identifier;
}

bool Aircraft::hasActivity(Activity a)
{
	for (Activity act : activityList) {
		if (act == a)
			return true;
	}
	return false;
}

std::string Aircraft::getModel()
{
	return this->model;
}

int Aircraft::getMaxAltitude()
{
	return this->maxAltitude;
}

void Aircraft::setModel(std::string model)
{
	this->model = model;
}

void Aircraft::setMaxAltitude(int maxAlt)
{
	this->maxAltitude = maxAlt;
}

void Aircraft::setId(int newID)
{
	this->identifier = newID;
}

void Aircraft::addNewActivity(Activity activity)
{
	this->activityList.push_back(activity);
}

void Aircraft::moveToNextId()
{
	this->nextID++;
}

std::string Aircraft::toString()
{
	return std::to_string(this->identifier) + " " + this->model;
}
