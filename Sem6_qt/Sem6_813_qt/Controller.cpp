#include "pch.h"
#include "Controller.h"
#include "Helicopter.h"
#include <fstream>
#include <iostream>

Controller::Controller()
{
}


Controller::~Controller()
{
}

std::vector<Aircraft*> Controller::getAll()
{
	return  this->repo.getData();
}

Activity mapToActivity(int activityCode) {
	return (Activity)activityCode;
}

std::string mapActivityToString(Activity a) {
	switch (a)
	{
	case PublicTransportation:
		return "PublicTransportation";
		break;
	case Medical:
		return "Medical";
		break;
	case Leisure:
		return "Leisure";
		break;
	case Military:
		return "Military";
		break;
	default:
		return "unknown";
		break;
	}
}

void Controller::addHelicopter(std::string model, int maxAltitude, int activityCode)
{
	Aircraft * newAircraft = new Helicopter();
	/*if (activityCode > 4) {
		throw InvalidActivityExcept()
	}*/
	Activity activity = mapToActivity(activityCode);

	newAircraft->setId(Aircraft::nextID);
	newAircraft->moveToNextId();

	newAircraft->setModel(model);
	newAircraft->setMaxAltitude(maxAltitude);
	newAircraft->addNewActivity(activity);

	this->repo.add(newAircraft);
}

void Controller::saveToFileByActivity(int activityCode)
{
	Activity activity = mapToActivity(activityCode);
	std::string activityName = mapActivityToString(activity);

	std::string fileName = activityName + ".out";
	std::vector<Aircraft*> filteredByActivity = this->repo.getByActivity(activity);

	std::ofstream out(fileName);

	std::cout << "filteredByActivity size " << filteredByActivity.size() << "\n";
	for (Aircraft* aircraft : filteredByActivity) {
		std::string aircraftAsString = aircraft->toString();
		out << aircraftAsString;
		std::cout << "add new: " << aircraftAsString;
	}
}

void Controller::removeById(int id)
{
	this->repo.removeById(id);
}
