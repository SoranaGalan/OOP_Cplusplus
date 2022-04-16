#pragma once
#include <qwidget.h>
#include <qobject.h>
#include <QMainWindow>
#include "Controller.h"
#include <QtWidgets/QApplication>
#include <qwidget.h>
#include <QVBoxLayout>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qlabel.h>
#include <qcheckbox.h>
#include <qpushbutton.h>
#include <QMessageBox>

class FormHelicopetr : public QMainWindow
{

private:
	Controller* ctrl;
	QLineEdit* maxAltitudeInput;
	QLineEdit* modelInput;
public:
	FormHelicopetr(QWidget *parent = nullptr);
	
	~FormHelicopetr();

public slots:
	void onBtnClick();
};

