#include "addchicken.h"
#include "ui_addchicken.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QDebug>
#include <QMessageBox>

using namespace std;

addChicken::addChicken(QWidget *parent) :
    QDialog(parent)
{
    m_chicken = nullptr;
    m_addBtn  = new QPushButton("&Add", this);
    m_exitBtn = new QPushButton("&Exit", this);
    m_id      = new QLineEdit(this);
    m_years   = new QLineEdit(this);
    m_days    = new QLineEdit(this);
    m_weigth  = new QLineEdit(this);
    m_type    = new QComboBox(this);
    m_eggs    = new QLineEdit(this);
    m_type->addItem("layer");
    m_type->addItem("broiler");


    QLabel* idLabel = new QLabel("Id:", this);
    QLabel* yearsLabel = new QLabel("Years:", this);
    QLabel* daysLabel = new QLabel("Days:", this);
    QLabel* weigthLabel = new QLabel("Weigth:", this);
    QLabel* typeLabel = new QLabel("Type:", this);
    QLabel* eggsLabel = new QLabel("Eggs:", this);

    QFormLayout* idLayout = new QFormLayout;
    QFormLayout* yearsLayout = new QFormLayout;
    QFormLayout* daysLayout = new QFormLayout;
    QFormLayout* weigthLayout = new QFormLayout;
    QFormLayout* typeLayout = new QFormLayout;
    QFormLayout* eggsLayout = new QFormLayout;

    idLayout->addRow(idLabel, m_id);
    yearsLayout->addRow(yearsLabel, m_years);
    daysLayout->addRow(daysLabel, m_days);
    weigthLayout->addRow(weigthLabel, m_weigth);
    typeLayout->addRow(typeLabel, m_type);
    eggsLayout->addRow(eggsLabel, m_eggs);

    QHBoxLayout* buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(m_addBtn);
    buttonLayout->addWidget(m_exitBtn);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addLayout(idLayout);
    layout->addLayout(yearsLayout);
    layout->addLayout(daysLayout);
    layout->addLayout(weigthLayout);
    layout->addLayout(typeLayout);
    layout->addLayout(eggsLayout);
    layout->addLayout(buttonLayout);

    this->setLayout(layout);

    connect(m_addBtn, &QPushButton::clicked, this, &addChicken::onAddClicked);
    connect(m_exitBtn, &QPushButton::clicked, this, &addChicken::onExitClicked);
    connect(m_type, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &addChicken::typeChanged);
}

addChicken::~addChicken()
{

}

Animal *addChicken::getChicken()
{
    return m_chicken;
}

void addChicken::onAddClicked(){
    bool idOk, yearsOk, daysOk, weigthOk, eggsOk;
    int id = m_id->text().toInt(&idOk, 10);
    int years = m_years->text().toInt(&yearsOk, 10);
    int days = m_days->text().toInt(&daysOk, 10);
    float weigth = m_weigth->text().toFloat(&weigthOk);
    qDebug() << QString::fromStdString(to_string(weigth));
    string type;
    if(m_type->currentIndex() == 0){
        type = "layer";
    }
    else
        type = "broiler";
    int eggs = 0;
    if(type == "layer")
        eggs = m_eggs->text().toInt(&eggsOk, 10);
    else
        eggsOk = true;

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
    if(eggs <  0)
        eggsOk  = false;

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
    else if(eggsOk == false){
        warning->setText("The number of eggs must be a natural number!");
        warning->show();
    }
    else{
        if(type == "layer"){
            m_chicken = new Chicken(id, Age{years, days}, weigth, type, eggs);
        }
        else{
            m_chicken = new Chicken(id, Age{years, days}, weigth, type);
        }
        this->close();
    }
}

void addChicken::onExitClicked(){
    this->close();
}

void addChicken::typeChanged(){
    qDebug() << "Gender changed!!!";
    if(m_type->currentIndex() == 1)
        m_eggs->setDisabled(1);
    else
        m_eggs->setEnabled(1);
}
