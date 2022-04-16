#ifndef ADDCHICKEN_H
#define ADDCHICKEN_H

#include <QDialog>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <Animal.h>
#include <Chicken.h>

class addChicken : public QDialog
{
    Q_OBJECT

public:
    explicit addChicken(QWidget *parent = nullptr);
    ~addChicken();
    Animal* getChicken();

public slots:
    void onAddClicked();
    void onExitClicked();
    void typeChanged();

private:
    QLineEdit* m_id;
    QLineEdit* m_years;
    QLineEdit* m_days;
    QLineEdit* m_weigth;
    QComboBox* m_type;
    QLineEdit* m_eggs;
    QPushButton* m_addBtn;
    QPushButton* m_exitBtn;

    Animal* m_chicken;
};

#endif // ADDCHICKEN_H
