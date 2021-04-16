#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pq.h"
#include <fstream>
#include <QMessageBox>
#include <iostream>
#include "collection.h"
#include "utils.h"
#include "workwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_createNew_clicked()
{
    PQ window;
    window.setWindowTitle("Параметры схемы");
    window.setModal(true);
    window.exec();
}

void MainWindow::on_exit_clicked()
{
    close();
}

void MainWindow::on_downloadOne_clicked()
{
    std::ifstream inputFile;
    inputFile.open("D:/Qt_Projects/untitled/input.txt");
    int* pq = utils::findPQ(inputFile);
    inputFile.close();
    Collection c(pq[0],pq[1]);
    delete [] pq;
    inputFile.open("D:/Qt_Projects/untitled/input.txt");
    c.fgetData(inputFile);
    inputFile.close();

    QWidget wid;
    WorkWindow window(&wid, &c);
    window.setWindowTitle("Электрическая схема");
    window.setModal(true);
    window.exec();

}
