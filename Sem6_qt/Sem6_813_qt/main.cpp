#include <QtWidgets/QApplication>
#include <qwidget.h>
#include <QVBoxLayout>
#include <qcombobox.h>
#include <qlineedit.h>
#include <qlabel.h>
#include <qcheckbox.h>
#include <qpushbutton.h>
#include "FormHelicopetr.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	FormHelicopetr form;

	form.show();
	
    return a.exec();
}
