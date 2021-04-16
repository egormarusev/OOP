#include "deletevideo.h"
#include "ui_deletevideo.h"

deletevideo::deletevideo(Collection *collection, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deletevideo)
{
    ui->setupUi(this);
    this->collection = collection;
    ui->spinBox->setMaximum(collection->getCount());
}


deletevideo::~deletevideo()
{
    delete ui;
}

void deletevideo::on_okButton_clicked()
{
    int index = ui->spinBox->value() - 1;
    collection->delVideo(index);
    this->close();
}

void deletevideo::on_cancelButton_clicked()
{
    this->close();
}
