#ifndef ADDANIMAL_H
#define ADDANIMAL_H

#include <QDialog>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include "addcow.h"
#include "addchicken.h"

class addAnimal : public QDialog
{
    Q_OBJECT

public:
    explicit addAnimal(QWidget *parent = nullptr);
    ~addAnimal();
    Animal* getAnimal();

public slots:
    void onAddClicked();
    void onExitClicked();

private:
   QComboBox* m_type;
   QPushButton* m_addBtn;
   QPushButton* m_exit;
   addCow* m_addCow;
   addChicken* m_addChicken;

   Animal* m_animal;
};

#endif // ADDANIMAL_H
