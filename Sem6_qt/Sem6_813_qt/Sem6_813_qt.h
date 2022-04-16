#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Sem6_813_qt.h"
#include "Controller.h"

class Sem6_813_qt : public QMainWindow
{
	Q_OBJECT

public:
	Sem6_813_qt(QWidget *parent = Q_NULLPTR);


private:
	Ui::Sem6_813_qtClass ui;
	Controller ctrl;

public slots:
	void addNewAircaft() {
		std::string model = this->ui.lineEdit->text().toStdString();
		int maxAltitude = this->ui.lineEdit_2->text().toInt();
		std::string act = this->ui.comboBox->currentText().toStdString();
		int activityInt = 0;
		if (act == "Medical")
			activityInt = 1;
		this->ctrl.addHelicopter(model, maxAltitude, activityInt);
	}


};
