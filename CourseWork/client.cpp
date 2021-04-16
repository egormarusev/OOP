#include "client.h"
#include "ui_client.h"
#include "changeinformation.h"
#include <QLabel>
#include <fstream>
#include "User.h"
#include <iostream>
#include "utils.h"
#include "myinvestment.h"
#include "BoughtCollection.h"
#include <fstream>

Client::Client(QWidget *parent, User *user, BoughtCollection *investments, PaperCollection* papers) :
    QDialog(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);

    this->user = user;
    this->investments = investments;
    this->papers = papers;

    on_update_clicked();
}

Client::~Client()
{
    delete ui;
}

void Client::on_backToMarket_clicked()
{
    close();
}

void Client::on_informationChanged_clicked()
{
    QWidget wid;
    ChangeInformation window(&wid, this->user);
    window.setWindowTitle("Изменить данные пользователя");
    window.setModal(true);
    window.exec();
}

void Client::on_update_clicked()
{
//    QString myName = user->getFirstName();
//    QString myLastName = user->getLastName();
//    double myProfit = user->getProfitNow();
//    double myMoneyBox = user->getMoneyBox();

    std::vector<std::string> data = utils::getDataFromUserFile();

    QString myName = utils::StdStringtoQString(data[0]);
    QString myLastName = utils::StdStringtoQString(data[1]);
    double myProfit = utils::StdStringtoQString(data[2]).toDouble();
    double myMoneyBox = utils::StdStringtoQString(data[3]).toDouble();
    double myNumberPapers = utils::StdStringtoQString(data[4]).toInt();

    user->setFirstName(myName);
    user->setLastName(myLastName);
    user->setMoneyBox(myMoneyBox);
    user->setProfitNow(myProfit);
    user->setNumberPapers(myNumberPapers);


    QString gap = " ";

    QString fullName = myName + gap + myLastName;
    ui->Name->setText(fullName);
    investments->profit();
    ui->Profit->setText(QString::number(user->getProfitNow()));
    ui->moneyBox->setText(QString::number(user->getMoneyBox()));
    if(utils::whatTimeIndex() == -1)
        ui->myInvestment->setEnabled(false);
    else
        ui->myInvestment->setEnabled(true);
    utils::addUserDataToFile(user->getFirstName(), user->getLastName(), user->getProfitNow(), user->getMoneyBox(), user->getNumberPapers());
}

void Client::on_myInvestment_clicked()
{
    QWidget wid;
    MyInvestment window(&wid, investments, user, papers);
    window.setWindowTitle("Мои инвестиции");
    window.setModal(true);
    window.exec();
}
