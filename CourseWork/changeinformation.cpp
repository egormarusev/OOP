#include "changeinformation.h"
#include "ui_changeinformation.h"
#include <QLabel>
#include "client.h"
#include <fstream>
#include "User.h"
#include "utils.h"

ChangeInformation::ChangeInformation(QWidget *parent, User* user) :
    QDialog(parent),
    ui(new Ui::ChangeInformation)
{
    ui->setupUi(this);
    this->user = user;

    QString myName = user->getFirstName();
    ui->nameEdit->setText(myName);

    QString myLastName = user->getLastName();
    ui->lastNameEdit->setText(myLastName);
}

ChangeInformation::~ChangeInformation()
{
    delete ui;
}

void ChangeInformation::on_Change_clicked()
{
    QString Qname = ui->nameEdit->text();
    user->setFirstName(Qname);

    QString QlastName = ui->lastNameEdit->text();
    user->setLastName(QlastName);

    utils::addUserDataToFile(ui->nameEdit->text(), ui->lastNameEdit->text(), user->getProfitNow(), user->getMoneyBox(), user->getNumberPapers());

    close();
}
