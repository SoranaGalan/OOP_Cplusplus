#include "addanimal.h"
#include "ui_addanimal.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QDebug>

addAnimal::addAnimal(QWidget *parent) :
    QDialog(parent)
{
    //QWidget* centralWidget = new QWidget(this);
    //this->setFixedSize(200,200);
    m_animal = nullptr;
    m_type = new QComboBox(this);
    m_type->addItem("Cow");
    m_type->addItem("Chicken");
    m_addBtn = new QPushButton("&Add", this);
    m_exit = new QPushButton("&Exit", this);

    QLabel* animalTypeLabel = new QLabel("Animal:", this);

    QVBoxLayout* centralLayout = new QVBoxLayout;

    QFormLayout* layout = new QFormLayout;
    layout->addRow(animalTypeLabel, m_type);

    QHBoxLayout* buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(m_addBtn);
    buttonsLayout->addWidget(m_exit);

    centralLayout->addLayout(layout);
    centralLayout->addLayout(buttonsLayout);

    //centralWidget->setLayout(centralLayout);
    this->setLayout(centralLayout);

    connect(m_addBtn, &QPushButton::clicked, this, &addAnimal::onAddClicked);
    connect(m_exit, &QPushButton::clicked, this, &addAnimal::onExitClicked);
}

addAnimal::~addAnimal()
{

}

Animal *addAnimal::getAnimal(){
    return m_animal;
}

void addAnimal::onAddClicked(){

    if(m_type->currentIndex() == 0){
        m_addCow = new addCow(this);
        this->close();
        m_addCow->exec();
        qDebug() << "Add pressed";
        m_animal = m_addCow->getCow();
    }
    else{
        m_addChicken = new addChicken(this);
        this->close();
        m_addChicken->exec();
        m_animal = m_addChicken->getChicken();
    }

}

void addAnimal::onExitClicked(){
    qDebug() << "Exit pressed";
    this->close();
}
