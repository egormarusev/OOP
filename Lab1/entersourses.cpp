#include "entersourses.h"
#include "ui_entersourses.h"
#include <QLineEdit>
#include <QLabel>
#include "collection.h"
EnterSourses::EnterSourses(QWidget *parent, int p, Collection *c) :
    QDialog(parent),
    ui(new Ui::EnterSourses)
{
    ui->setupUi(this);
    collection = c;
    this->p = p;

    for(int i = 0; i < p; i++)
    {
        lines.append(new QLineEdit());
        lines.at(i)->setObjectName(QString("lineEditCurr%1").arg(i));
        lines.at(i)->setText(QString::number(collection->getCurrentSourse()[i]));

        labels.append(new QLabel(QString::number(i+1)));
        labels.at(i)->setAlignment(Qt::AlignCenter);
    }

    for(int i = 0; i < p; i++)
    {
        lines.append(new QLineEdit());
        lines.at(i+p)->setObjectName(QString("lineEditPow%1").arg(i));
        lines.at(i+p)->setText(QString::number(collection->getPowerSourse()[i]));
    }


    for (int i = 0;i < p;i++)
    {
        ui->gridLayout->addWidget(labels.at(i),0,i+1);
        ui->gridLayout->addWidget(lines.at(i),1,i+1);
    }
    for (int i = 0;i < p;i++)
    {
        ui->gridLayout->addWidget(lines.at(i+p),2,i+1);
    }
}

EnterSourses::~EnterSourses()
{
    delete ui;
}

void EnterSourses::on_enterSourses_clicked()
{
    double* elementsCurr = new double[p];
    double* elementsPow = new double[p];
    for (int i = 0;i < p ; i++)
    {
        elementsCurr[i] = lines[i]->text().toDouble();
        elementsPow[i] = lines[i + p]->text().toDouble();
    }
    collection->setPowerSourse(elementsPow);
    collection->setCurrentSourse(elementsCurr);

    delete [] elementsCurr;
    delete [] elementsPow;

    close();
}
