#include "enterfrequency.h"
#include "ui_enterfrequency.h"
#include "collection.h"

EnterFrequency::EnterFrequency(QWidget *parent, Collection *c) :
    QDialog(parent),
    ui(new Ui::EnterFrequency)
{
    collection = c;
    ui->setupUi(this);
    ui->frequency->setText(QString::number(collection->getFrequency()));
}

EnterFrequency::~EnterFrequency()
{
    delete ui;
}

void EnterFrequency::on_enterFrequency_clicked()
{
    collection->setFrequency(ui->frequency->text().toDouble());
    close();
}
