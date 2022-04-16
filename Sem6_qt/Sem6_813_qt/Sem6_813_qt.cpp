#include "Sem6_813_qt.h"

Sem6_813_qt::Sem6_813_qt(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	connect(this->ui.pushButton, &QPushButton::released, this, &Sem6_813_qt::addNewAircaft);
}
