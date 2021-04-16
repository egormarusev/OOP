#include "enterelements.h"
#include "ui_enterelements.h"
#include <QLineEdit>
#include <QLabel>
#include <iostream>
#include "utils.h"

EnterElements::EnterElements(QWidget *parent, int p, Collection* c) :
    QDialog(parent),
    ui(new Ui::EnterElements)
{
    ui->setupUi(this);
    this->p = p;
    collection = c;


    for(int i = 0; i < p; i++)
    {
        lines.append(new QLineEdit());
        lines.at(i)->setObjectName(QString("lineEditR%1").arg(i));

        //collection->getElement(0,i)
        lines.at(i)->setText(QString::number(collection->getElementR(0,i).getElementResistance()));

        labels.append(new QLabel(QString::number(i+1)));
        labels.at(i)->setAlignment(Qt::AlignCenter);
    }

    for(int i = 0; i < p; i++)
    {
        lines.append(new QLineEdit());
        lines.at(i+p)->setObjectName(QString("lineEditLC%1").arg(i));

        lines.at(i+p)->setText(QString::number(collection->getElementLC(1,i).getElementResistance()));
    }

    //utils::cleanMemory(el,2,p);

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

EnterElements::~EnterElements()
{
    delete ui;
}

void EnterElements::on_enterElements_clicked()
{
    double* elementsR = new double[p];
    double* elementsLC = new double[p];
    for (int i = 0;i < p ; i++)
    {
        elementsR[i] = lines[i]->text().toDouble();
        elementsLC[i] = lines[i + p]->text().toDouble();
    }
    Element*** elements = utils::RLCtoCollection(elementsR, elementsLC, p);
    collection->setCollection(elements);
    utils::cleanMemory(elements, 2, p);
    delete [] elementsR;
    delete [] elementsLC;

    close();
}
