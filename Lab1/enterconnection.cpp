#include "enterconnection.h"
#include "ui_enterconnection.h"
#include "collection.h"
#include "utils.h"

EnterConnection::EnterConnection(QWidget *parent, int p, int q, Collection* c) :
    QDialog(parent),
    ui(new Ui::EnterConnection)
{
    ui->setupUi(this);
    collection = c;
    this->p = p;
    this->q = q;

    for(int i = 0; i < p; i++)
    {
        labels.append(new QLabel(QString::number(i+1)));
        labels.at(i)->setAlignment(Qt::AlignCenter);
    }

    for(int i = 0; i < q-1; i++)
    {
        labels.append(new QLabel(QString::number(i+1)));
        labels.at(p + i)->setAlignment(Qt::AlignCenter);
    }

    int m = 0;
    for(int i = 0; i < (q-1); i++)
    {
        for(int j = 0; j < p; j++)
        {
            lines.append(new QComboBox());
            lines.at(m)->addItem("0");
            lines.at(m)->addItem("1");
            lines.at(m)->addItem("-1");

            lines.at(m)->setCurrentText(QString::number(collection->getConnection()[i][j]));
            lines.at(m)->setObjectName(QString("ComboboxCon%1").arg(m));
            m++;
        }
    }


    for (int i = 1;i < p;i++)
    {
        ui->gridLayout->addWidget(labels.at(i),0,i+1);
    }

    for (int i = 1;i < q-1;i++)
    {
        ui->gridLayout->addWidget(labels.at(i+p),i+1,0);
    }
    int n = 0;
    for (int i = 0;i < q-1;i++)
    {
        for (int j = 0;j < p;j++)
        {
            ui->gridLayout->addWidget(lines.at(n),i+1,j+1);
            n++;
        }
    }

}

EnterConnection::~EnterConnection()
{
    delete ui;
}

void EnterConnection::on_enterConnection_clicked()
{

    double** conn = new double*[q-1];
    int n = 0;
    for (int i = 0;i < q-1 ; i++)
    {
        conn[i] = new double[p];
        for (int j = 0;j < p ; j++)
        {
            conn[i][j] = lines[n]->currentText().toInt();
            n++;
        }
    }
    collection->setConnection(conn);

    utils::cleanMemory(conn,q-1);

    close();

}
