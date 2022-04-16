#ifndef ADDCOW_H
#define ADDCOW_H

#include <QDialog>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include "Cow.h"

class addCow : public QDialog
{
    Q_OBJECT

public:
    explicit addCow(QWidget *parent = nullptr);
    ~addCow();
    Animal* getCow();
public slots:
    void onAddClicked();
    void onExitClicked();
    void genderChanged();
private:
    QLineEdit* m_id;
    QLineEdit* m_years;
    QLineEdit* m_days;
    QLineEdit* m_weigth;
    QComboBox* m_gender;
    QComboBox* m_isVaxx;
    QLineEdit* m_milk;
    QPushButton* m_addBtn;
    QPushButton* m_exitBtn;
    Cow* m_cow;

};

#endif // ADDCOW_H
