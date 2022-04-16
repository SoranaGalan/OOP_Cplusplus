#include "addcow.h"
#include "ui_addcow.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QDebug>
#include <vector>
#include "Animal.h"
#include <QMessageBox>
#include "Age.h"

addCow::addCow(QWidget *parent) :
    QDialog(parent)
{
    m_cow = nullptr;
    m_addBtn  = new QPushButton("&Add", this);
    m_exitBtn = new QPushButton("&Exit", this);
    m_id      = new QLineEdit(this);
    m_years   = new QLineEdit(this);
    m_days    = new QLineEdit(this);
    m_weigth  = new QLineEdit(this);
    m_gender  = new QComboBox(this);
    m_isVaxx  = new QComboBox(this);
    m_milk    = new QLineEdit(this);
    m_gender->addItem("female");
    m_gender->addItem("male");
    m_isVaxx->addItem("False");
    m_isVaxx->addItem("True");

    QLabel* idLabel = new QLabel("Id:", this);
    QLabel* yearsLabel = new QLabel("Years:", this);
    QLabel* daysLabel = new QLabel("Days:", this);
    QLabel* weigthLabel = new QLabel("Weigth:", this);
    QLabel* genderLabel = new QLabel("Gender:", this);
    QLabel* vaxxLabel = new QLabel("Vaccinated:", this);
    QLabel* milkLabel = new QLabel("Milk:", this);

    QFormLayout* idLayout = new QFormLayout;
    QFormLayout* yearsLayout = new QFormLayout;
    QFormLayout* daysLayout = new QFormLayout;
    QFormLayout* weigthLayout = new QFormLayout;
    QFormLayout* genderLayout = new QFormLayout;
    QFormLayout* vaxxLayout = new QFormLayout;
    QFormLayout* milkLayout = new QFormLayout;

    idLayout->addRow(idLabel, m_id);
    yearsLayout->addRow(yearsLabel, m_years);
    daysLayout->addRow(daysLabel, m_days);
    weigthLayout->addRow(weigthLabel, m_weigth);
    genderLayout->addRow(genderLabel, m_gender);
    vaxxLayout->addRow(vaxxLabel, m_isVaxx);
    milkLayout->addRow(milkLabel, m_milk);

    QHBoxLayout* buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(m_addBtn);
    buttonLayout->addWidget(m_exitBtn);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addLayout(idLayout);
    layout->addLayout(yearsLayout);
    layout->addLayout(daysLayout);
    layout->addLayout(weigthLayout);
    layout->addLayout(genderLayout);
    layout->addLayout(vaxxLayout);
    layout->addLayout(milkLayout);
    layout->addLayout(buttonLayout);

    this->setLayout(layout);

    connect(m_addBtn, &QPushButton::clicked, this, &addCow::onAddClicked);
    connect(m_exitBtn, &QPushButton::clicked, this, &addCow::onExitClicked);
    connect(m_gender, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &addCow::genderChanged);
}

addCow::~addCow()
{

}

Animal *addCow::getCow(){
    return m_cow;
}

void addCow::onAddClicked(){
    bool idOk, yearsOk, daysOk, weigthOk, milkOk;
    int id = m_id->text().toInt(&idOk, 10);
    int years = m_years->text().toInt(&yearsOk, 10);
    int days = m_days->text().toInt(&daysOk, 10);
    float weigth = m_weigth->text().toFloat(&weigthOk);
    qDebug() << QString::fromStdString(to_string(weigth));
    char gender;
    if(m_gender->currentIndex() == 0){
        gender = 'f';
    }
    else
        gender = 'm';
    bool isVaxxed;
    if(m_isVaxx->currentIndex() == 0)
        isVaxxed = false;
    else
        isVaxxed = true;
    float milk = 0;
    if(gender == 'f')
        milk = m_milk->text().toFloat(&milkOk);
    else
        milkOk = true;

    vector<int> ids = Animal::getAllIDs();
    for(int i = 0 ; i < ids.size();i++){
        if(id == ids[i]){
            idOk = false;
            break;
        }
    }
    if(years < 0)
        yearsOk = false;
    if(days < 0)
        daysOk = false;
    if(weigth < 0)
        weigthOk = false;
    if(milk <  0)
        milkOk  = false;

    QMessageBox* warning = new QMessageBox;
    if(idOk == false){
        warning->setText("Id not valid!");
        warning->show();
    }
    else if(yearsOk == false){
        warning->setText("The numbers of years must be a natural number!");
        warning->show();
    }
    else if(daysOk == false){
            warning->setText("The numbers of days must be a natural number!");
            warning->show();
    }
    else if(weigthOk == false){
            warning->setText("The weigth must be a natural number!");
            warning->show();
    }
    else if(milkOk == false){
        warning->setText("The number of liters of milk must be a natural number!");
        warning->show();
    }
    else{
        if(gender == 'f'){
            m_cow = new Cow(id, Age{years, days}, weigth, gender, isVaxxed, milk);
        }
        else{
            m_cow = new Cow(id, Age{years, days}, weigth, gender, isVaxxed);
        }
        this->close();
    }
}

void addCow::onExitClicked(){
    this->close();
}

void addCow::genderChanged(){
    qDebug() << "Gender changed!!!";
    if(m_gender->currentIndex() == 1)
        m_milk->setDisabled(1);
    else
        m_milk->setEnabled(1);
}
