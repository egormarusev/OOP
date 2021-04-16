#include "pq.h"
#include "ui_pq.h"
#include "collection.h"
#include "workwindow.h"

PQ::PQ(QWidget *parent) : QDialog(parent), ui(new Ui::PQ)
{
    ui->setupUi(this);
}

PQ::~PQ()
{
    delete ui;
}

void PQ::on_createNew_clicked()
{
    QWidget wid;
    int p = ui->ribs->text().toInt();
    int q = ui->nodes->text().toInt();
    Collection c(p, q);
    WorkWindow window(&wid, &c);
    window.setWindowTitle("Электрическая схема");
    window.setModal(true);
    window.exec();
    close();
}
