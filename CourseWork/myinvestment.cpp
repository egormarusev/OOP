#include "myinvestment.h"
#include "ui_myinvestment.h"
#include "BoughtCollection.h"
#include <algorithm>
#include <QMessageBox>
#include "utils.h"
#include "User.h"

MyInvestment::MyInvestment(QWidget *parent, BoughtCollection* investments, User* user, PaperCollection* papers) :
    QDialog(parent),
    ui(new Ui::MyInvestment)
{
    ui->setupUi(this);

    this->investments = investments;
    this->user = user;
    this->papers = papers;

    ui->chooseInvestments->addItem("Yandex");
    ui->chooseInvestments->addItem("Apple");
    ui->chooseInvestments->addItem("Samsung");
    ui->chooseInvestments->addItem("VTB");
    ui->chooseInvestments->addItem("Sber");
    ui->chooseInvestments->addItem("Sony");

    on_update_clicked();
}

MyInvestment::~MyInvestment()
{
    delete ui;
}

void MyInvestment::on_sell_clicked()
{
    QString name = ui->chooseInvestments->currentText();
    int number = ui->chooseCount->text().toInt();
    if(user->getNumberPapers() > 0 && investments->checkHaveInvestmentByName(name))
    {
        if(number > 0 && number <= investments->getInvestment(name).getNumberPapers())
        {
            user->setNumberPapers(user->getNumberPapers() - number);
            investments->sellInvestment(name, number);
            utils::addInvestmentFile(investments);
            utils::addUserDataToFile(user->getFirstName(),user->getLastName(),user->getProfitNow(),user->getMoneyBox(), user->getNumberPapers());
            QMessageBox::about(this, QString("Продажа") + name, "Продажа произведена успешно");
        }
        else
        {
            QMessageBox::warning(this, QString("Продажа") + name, "Неверное кол-во бумаг");
        }
    }
    else
    {
        QMessageBox::warning(this, QString("Продажа") + name, "Неверное кол-во бумаг");
    }
}

void MyInvestment::on_backToCabinet_clicked()
{
    close();
}

void MyInvestment::on_update_clicked()
{
//    ui->chooseInvestments->addItem("Yandex");
//    ui->chooseInvestments->addItem("Apple");
//    ui->chooseInvestments->addItem("Samsung");
//    ui->chooseInvestments->addItem("VTB");
//    ui->chooseInvestments->addItem("Sber");
//    ui->chooseInvestments->addItem("Sony");

    ui->showInvestment->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->showInvestment->setColumnCount(3);
    ui->showInvestment->setRowCount(7);
    ui->showInvestment->setColumnWidth(0, 280);
    ui->showInvestment->setColumnWidth(1, 280);
    ui->showInvestment->setColumnWidth(2, 280);
    ui->showInvestment->setItem(0,0,new QTableWidgetItem("    Название"));
    ui->showInvestment->setItem(0,1,new QTableWidgetItem("    Цена"));
    ui->showInvestment->setItem(0,2,new QTableWidgetItem("    Количество"));

    ui->showInvestment->setItem(1,0,new QTableWidgetItem("    Yandex"));
    ui->showInvestment->setItem(2,0,new QTableWidgetItem("    Apple"));
    ui->showInvestment->setItem(3,0,new QTableWidgetItem("    Samsung"));
    ui->showInvestment->setItem(4,0,new QTableWidgetItem("    VTB"));
    ui->showInvestment->setItem(5,0,new QTableWidgetItem("    Sber"));
    ui->showInvestment->setItem(6,0,new QTableWidgetItem("    Sony"));

    QVector<QString> names = {"Yandex", "Apple","Samsung","VTB","Sber","Sony"};
    int index = 0;
    double price;
    int num;
    for(int i = 0; i < investments->getCount(); i++)
    {
        if(names.contains(investments->getInvestment(i).getPaperName()))
        {
            index = names.indexOf(investments->getInvestment(i).getPaperName());
            price = papers->getPaper(names.at(index)).getPrice();
            num = investments->getInvestment(i).getNumberPapers();
            ui->showInvestment->setItem(index+1,1,new QTableWidgetItem(QString::number(price)));
            ui->showInvestment->setItem(index+1,2,new QTableWidgetItem(QString::number(num)));
        }
    }

    for(int i = 0; i < 6; i++)
    {
        if(!investments->checkHaveInvestmentByName(names.at(i)))
        {
            ui->showInvestment->setItem(i+1,1,new QTableWidgetItem(QString(" ")));
            ui->showInvestment->setItem(i+1,2,new QTableWidgetItem(QString(" ")));
        }
    }

    ui->showInvestment->update();
    ui->showInvestment->setShowGrid(false);
}
