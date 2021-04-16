#include "potentials.h"
#include "ui_potentials.h"

Potentials::Potentials(QWidget *parent, Collection *c, int q) :
    QDialog(parent),
    ui(new Ui::Potentials)
{
    collection = c;
    this->q = q;
    ui->setupUi(this);

    collection->solvePotentials();

    for(int i = 0; i < q-1; i++)
    {
        lines.append(new QLineEdit());
        lines.at(i)->setObjectName(QString("lineEditU0%1").arg(i));

        lines.at(i)->setText(QString::number(collection->getNodalPotentials()[i]));

        labels.append(new QLabel(QString::number(i+1)));
        labels.at(i)->setAlignment(Qt::AlignCenter);
    }


    for (int i = 0;i < q-1;i++)
    {
        ui->gridLayout->addWidget(labels.at(i),0,i+1);
        ui->gridLayout->addWidget(lines.at(i),1,i+1);
    }
}

Potentials::~Potentials()
{
    delete ui;
}

void Potentials::on_Ok_clicked()
{
    close();
}
