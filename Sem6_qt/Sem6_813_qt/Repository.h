#pragma once
#include <vector>
#include "Aircraft.h"
#include <string>

class Repository
{
private:
	std::vector<Aircraft*> data;
	std::string jsonFileName;
public:
	Repository();
	~Repository();

	std::vector<Aircraft*> getData() const;
	void add(Aircraft* newAircraft);
	std::vector<Aircraft*> getByActivity(Activity activity);
	void removeById(int id);

	void loadFromJson();
	void saveToJson();
};

