#include "workwindow.h"
#include "ui_workwindow.h"
#include "collection.h"
#include "enterelements.h"
#include "enterconnection.h"
#include "entersourses.h"
#include "enterfrequency.h"
#include "potentials.h"
#include "fullresistance.h"
#include <fstream>
#include <QMessageBox>
#include <iostream>
WorkWindow::WorkWindow(QWidget *parent, Collection* c) : QDialog(parent), ui(new Ui::WorkWindow)
{
    collection = c;
    ui->setupUi(this);
}

WorkWindow::~WorkWindow()
{
    delete ui;
}

void WorkWindow::on_enterElements_clicked()
{
    QWidget wid;
    EnterElements window(&wid, collection->getNumberRibs(), collection);
    window.setWindowTitle("Элементы схемы");
    window.setModal(true);
    window.exec();
}

void WorkWindow::on_enterConnection_clicked()
{
    QWidget wid;
    EnterConnection window(&wid, collection->getNumberRibs(), collection->getNumberNodes(), collection);
    window.setWindowTitle("Соединения схемы");
    window.setModal(true);
    window.exec();

}

void WorkWindow::on_enterSourses_clicked()
{
    QWidget wid;
    EnterSourses window(&wid, collection->getNumberRibs(), collection);
    window.setWindowTitle("Источники");
    window.setModal(true);
    window.exec();
}

void WorkWindow::on_enterFrequency_clicked()
{
    QWidget wid;
    EnterFrequency window(&wid, collection);
    window.setWindowTitle("Частота тока");
    window.setModal(true);
    window.exec();
}

void WorkWindow::on_findPotentials_clicked()
{
    QWidget wid;
    Potentials window(&wid, collection, collection->getNumberNodes());
    window.setWindowTitle("Нахождение узловых потенциалов цепи");
    window.setModal(true);
    window.exec();
}

void WorkWindow::on_findFullResistance_clicked()
{
    QWidget wid;
    FullResistance window(&wid, collection);
    window.setWindowTitle("Нахождение полного сопротивления");
    window.setModal(true);
    window.exec();
}

void WorkWindow::on_deleteAll_clicked()
{
    collection->deleteAll();
    QMessageBox::about(this, "Удаление схемы", "Всё удалено");
    close();
}

void WorkWindow::on_exit_clicked()
{
    close();
}

void WorkWindow::on_SaveToFile_clicked()
{
    std::ofstream outputFile;
    outputFile.open("D:/Qt_Projects/untitled/output.txt");
    if(outputFile.is_open())
    {
        std::cout<<"Opened";
    }
    collection->fprintData(outputFile);
    QMessageBox::about(this, "Сохранение схемы", "Файл \"output.txt\" сохранен");
    outputFile.close();
}
