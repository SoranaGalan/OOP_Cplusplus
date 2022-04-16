#pragma once
#include <vector>
#include <string>
enum Activity {PublicTransportation, Medical, Leisure, Military};

class Aircraft
{
protected:
	int identifier;
	std::string model;
	std::vector<Activity> activityList;
	int maxAltitude;
	std::string className;

public:
	static int nextID;
	Aircraft();
	~Aircraft();
	int getId();
	bool hasActivity(Activity a);
	std::string getModel();
	int getMaxAltitude();
	void setModel(std::string model);
	void setMaxAltitude(int maxAlt);
	void setId(int newID);
	void addNewActivity(Activity activity);
	void moveToNextId();
	virtual std::string toString();
};

