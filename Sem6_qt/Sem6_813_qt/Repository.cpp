#include "pch.h"
#include "Repository.h"
#include "Helicopter.h"
#include <qjsondocument.h>
#include <qjsonobject.h>
#include <qjsonarray.h>
#include <qfile.h>
#include <qstring.h>

Repository::Repository()
{
	this->jsonFileName = "persistance.json";
	this->loadFromJson();
}


Repository::~Repository()
{
}

std::vector<Aircraft*> Repository::getData() const
{
	return data;
}

void Repository::add(Aircraft * newAircraft)
{
	
	this->data.push_back(newAircraft);

}

std::vector<Aircraft*> Repository::getByActivity(Activity activity)
{
	std::vector<Aircraft*> filteredVector;
	for (auto aircraft : this->data) {
		if (aircraft->hasActivity(activity))
			filteredVector.push_back(aircraft);
	}
	return filteredVector;
}

void Repository::removeById(int id)
{
	for (std::vector<Aircraft*>::iterator it = this->data.begin(); it != this->data.end(); it++) {
		
		if ((*it)->getId() == id) {
			Aircraft* item = (*it);
			this->data.erase(it);
			delete item;
			break;
		}
	}
	this->saveToJson();
	
}

void Repository::loadFromJson()
{
	QFile persistanceFile(QString::fromStdString(this->jsonFileName));
	persistanceFile.open(QFile::ReadOnly);

	QJsonDocument doc = QJsonDocument().fromJson(persistanceFile.readAll());
	QJsonObject rootObject = doc.object();
	QJsonArray rootArray = rootObject.value("aircrafts").toArray();

	for (auto itemObj : rootArray) {
		QJsonObject aircraftJsonObj = itemObj.toObject();
		int itemId = aircraftJsonObj.value("id").toInt();
		int maxAltitude = aircraftJsonObj.value("maxAltitude").toInt();
		std::string model = aircraftJsonObj.value("model").toString().toStdString();
		std::string aircraftType = aircraftJsonObj.value("type").toString().toStdString();

		if (aircraftType == "helicopter") {
			Helicopter *h = new Helicopter();
			h->setId(itemId);
			h->setMaxAltitude(maxAltitude);
			this->add(h);
		}
	}
}

void Repository::saveToJson()
{
	QJsonDocument doc;
	QJsonObject rootObject;
	QJsonArray rootArray;

	for (Aircraft* aircraft : this->getData()) {
		QJsonObject aircraftObj;
		aircraftObj.insert("id", aircraft->getId());
		aircraftObj.insert("maxAltitude", aircraft->getMaxAltitude());
		aircraftObj.insert("model", QString::fromStdString(aircraft->getModel()));
		rootArray.push_back(aircraftObj);
	}

	rootObject.insert("aircrafts", rootArray);
	doc.setObject(rootObject);

	QFile persistenceFile(QString::fromStdString(this->jsonFileName));
	persistenceFile.open(QFile::WriteOnly);
	persistenceFile.write(doc.toJson());
	persistenceFile.close();

}
