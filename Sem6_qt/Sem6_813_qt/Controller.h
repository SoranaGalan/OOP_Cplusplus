#pragma once
#include "Repository.h"
#include <string>
class Controller
{
private:
	Repository repo;
public:
	Controller();
	~Controller();

	std::vector<Aircraft*> getAll();
	void addHelicopter(std::string model, int maxAltitude, int activity);
	void saveToFileByActivity(int activity);
	void removeById(int id);
};

