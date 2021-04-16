#include "fullresistance.h"
#include "ui_fullresistance.h"
#include "collection.h"

FullResistance::FullResistance(QWidget *parent, Collection* c) :
    QDialog(parent),
    ui(new Ui::FullResistance)
{
    collection = c;
    ui->setupUi(this);
    int p = collection->getNumberRibs();
    for (int i = 0;i < p ; i++)
    {
        ui->comboBoxR->addItem(QString::number(i+1));
        ui->comboBoxLC->addItem(QString::number(i+1));
    }
}

FullResistance::~FullResistance()
{
    delete ui;
}

void FullResistance::on_EnterNumbers_clicked()
{
    double X = collection->solveFullResistance(ui->comboBoxR->currentText().toDouble()-1, ui->comboBoxLC->currentText().toDouble()-1);
    ui->output->setText(QString::number(X));
}

void FullResistance::on_Exit_clicked()
{
    close();
}
