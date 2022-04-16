#include "FormHelicopetr.h"
#include <QtWidgets/QApplication>
#include <qwidget.h>
#include <QVBoxLayout>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qlabel.h>
#include <qcheckbox.h>
#include <qpushbutton.h>
#include <QMessageBox>


FormHelicopetr::FormHelicopetr(QWidget * parent)
	: QMainWindow(parent)
{
	QWidget* centralWidget = new QWidget();

	QLabel* label = new QLabel("max altitude:");
	QVBoxLayout* verticalLayout = new QVBoxLayout();
	verticalLayout->addWidget(label);

	this->maxAltitudeInput = new QLineEdit();
	verticalLayout->addWidget(this->maxAltitudeInput);

	QLabel *labeModel = new QLabel("model:");
	verticalLayout->addWidget(labeModel);

	modelInput = new QLineEdit();
	verticalLayout->addWidget(modelInput);

	QComboBox *activitiesBox = new QComboBox();
	activitiesBox->addItem("PublicTransportation");
	activitiesBox->addItem("Medical");
	activitiesBox->addItem("Leisure");
	verticalLayout->addWidget(activitiesBox);

	QLabel *labeIsPrivate = new QLabel("is private:");
	verticalLayout->addWidget(labeIsPrivate);

	QCheckBox *isPrivateChk = new QCheckBox();
	verticalLayout->addWidget(isPrivateChk);

	QPushButton* saveBtn = new QPushButton();
	saveBtn->setText("mare buton rosu");
	verticalLayout->addWidget(saveBtn);

	QObject::connect(saveBtn, &QPushButton::released, this, &FormHelicopetr::onBtnClick);

	centralWidget->setLayout(verticalLayout);
	this->setCentralWidget(centralWidget);
}
void FormHelicopetr::onBtnClick() {
	int maxAlt = maxAltitudeInput->text().toInt();
	std::string model = modelInput->text().toStdString();
	
	ctrl->addHelicopter();

	QMessageBox msgBox;
	msgBox.setText("ok");
	msgBox.exec();
}


FormHelicopetr::~FormHelicopetr()
{
}
