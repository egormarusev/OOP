#include "mainwindow.h"

#include <QApplication>

#include "utils.h"
#include <iostream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    utils::whatTime();

    //std::cout<< utils::whatTime();
    MainWindow w;
    w.setWindowTitle("Инвест копилка");
    w.show();
    return a.exec();
}
