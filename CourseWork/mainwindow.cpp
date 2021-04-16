#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graphics.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include "client.h"
#include "User.h"
#include <iostream>
#include <fstream>
#include "utils.h"
#include <QMessageBox>
#include "PaperCollection.h"
#include "SecurityPaper.h"
#include "BoughtCollection.h"
#include "Investment.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    QVector<QString> names = {"Yandex", "Apple","Samsung", "VTB", "Sber", "Sony"};

    PaperCollection* papers = new PaperCollection();
    for (int i = 0;i < 6;i++ )
    {
        if(i < 3)
        {
            SecurityPaper *paper = new SecurityPaper(names.at(i), 0);
            papers->addPaper(paper);
        }
        else
        {
            SecurityPaper *paper = new SecurityPaper(names.at(i), 0);
            papers->addPaper(paper);
        }
    }
    this->papers = papers;


    ui->TableStocks->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TableStocks->setColumnCount(3);
    ui->TableStocks->setRowCount(2);
    ui->TableStocks->setColumnWidth(0, 280);
    ui->TableStocks->setColumnWidth(1, 280);
    ui->TableStocks->setColumnWidth(2, 280);
    ui->TableStocks->setItem(0,0,new QTableWidgetItem("    Yandex"));
    ui->TableStocks->setItem(0,1,new QTableWidgetItem("    Apple"));
    ui->TableStocks->setItem(0,2,new QTableWidgetItem("    Samsung"));
    ui->TableStocks->update();
    ui->TableStocks->setShowGrid(false);


    ui->TableBonds->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TableBonds->setColumnCount(3);
    ui->TableBonds->setRowCount(2);
    ui->TableBonds->setColumnWidth(0, 280);
    ui->TableBonds->setColumnWidth(1, 280);
    ui->TableBonds->setColumnWidth(2, 280);
    ui->TableBonds->setItem(0,0,new QTableWidgetItem("    VTB"));
    ui->TableBonds->setItem(0,1,new QTableWidgetItem("    Sber"));
    ui->TableBonds->setItem(0,2,new QTableWidgetItem("    Sony"));

    ui->TableBonds->update();
    ui->TableBonds->setShowGrid(false);

    utils::createUserFile();
    utils::createInvestmentFile();
    utils::newPrice();


    std::vector<std::string> data = utils::getDataFromUserFile();

    QString name = utils::StdStringtoQString(data[0]);
    QString lastName = utils::StdStringtoQString(data[1]);
    double profit = utils::StdStringtoQString(data[2]).toDouble();
    double moneyBox = utils::StdStringtoQString(data[3]).toDouble();
    double numberPapers = utils::StdStringtoQString(data[4]).toInt();


    this->user =  new User(name, lastName, profit, moneyBox, numberPapers);

    BoughtCollection *investments = new BoughtCollection(papers, user);
    std::ifstream file("Investments.txt");
    if(!utils::isEmpty(file))
    {
        investments->setInvestments(utils::getInvestmentsFromFile());
        investments->setCountInvestment(user->getNumberPapers());
        user->setNumberPapers(0);
    }
    this->investments = investments;


    ui->ChoosePaper->addItem("Yandex");
    ui->ChoosePaper->addItem("Apple");
    ui->ChoosePaper->addItem("Samsung");
    ui->ChoosePaper->addItem("VTB");
    ui->ChoosePaper->addItem("Sber");
    ui->ChoosePaper->addItem("Sony");


    on_update_clicked();

    if(utils::whatTimeIndex() == -1)
        ui->buy->setEnabled(false);
    else
        ui->buy->setEnabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_showGraphic_clicked()
{
    QWidget wid;
    std::vector<QString> names = {"Yandex", "Apple","Samsung", "VTB", "Sber", "Sony"};
    QString name = ui->ChoosePaper->currentText();
    int index = 0;
    for (int i = 0;i < 6 ;i++ )
    {
       if(name == names[i])
           index = i;
    }
    Graphics window(&wid, index);
    window.setWindowTitle("Графики");
    window.setModal(true);
    window.exec();
}


void MainWindow::on_ClientMenu_clicked()
{
    QWidget wid;
    Client window(&wid, this->user, this->investments, this->papers);
    window.setWindowTitle("Личный кабинет");
    window.setModal(true);
    window.exec();
}

void MainWindow::on_update_clicked()
{
    int index = utils::whatTimeIndex();
    if (index != -1)
    {
        std::ifstream File("PriceList.txt" );
        std::vector<std::vector<double>> prices = utils::parseData(File);
        for (int i = 0;i < 6; i++)
        {
            double oldPrice = papers->getPaper(i).getPrice();
            double newPrice = prices.at(i).at(index);
            if(oldPrice != newPrice)
            {
                papers->setPrice(papers->getPaper(i).getName(),newPrice);
            }
        }

        ui->TableStocks->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->TableStocks->setColumnCount(3);
        ui->TableStocks->setRowCount(2);
        ui->TableStocks->setColumnWidth(0, 280);
        ui->TableStocks->setColumnWidth(1, 280);
        ui->TableStocks->setColumnWidth(2, 280);
        ui->TableStocks->setItem(0,0,new QTableWidgetItem("    Yandex"));
        ui->TableStocks->setItem(0,1,new QTableWidgetItem("    Apple"));
        ui->TableStocks->setItem(0,2,new QTableWidgetItem("    Samsung"));

        ui->TableStocks->setItem(1,0,new QTableWidgetItem(QString::number(prices[0][index])));
        ui->TableStocks->setItem(1,1,new QTableWidgetItem(QString::number(prices[1][index])));
        ui->TableStocks->setItem(1,2,new QTableWidgetItem(QString::number(prices[2][index])));

        ui->TableStocks->update();
        ui->TableStocks->setShowGrid(false);


        ui->TableBonds->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->TableBonds->setColumnCount(3);
        ui->TableBonds->setRowCount(2);
        ui->TableBonds->setColumnWidth(0, 280);
        ui->TableBonds->setColumnWidth(1, 280);
        ui->TableBonds->setColumnWidth(2, 280);
        ui->TableBonds->setItem(0,0,new QTableWidgetItem("    VTB"));
        ui->TableBonds->setItem(0,1,new QTableWidgetItem("    Sber"));
        ui->TableBonds->setItem(0,2,new QTableWidgetItem("    Sony"));

        ui->TableBonds->setItem(1,0,new QTableWidgetItem(QString::number(prices[3][index])));
        ui->TableBonds->setItem(1,1,new QTableWidgetItem(QString::number(prices[4][index])));
        ui->TableBonds->setItem(1,2,new QTableWidgetItem(QString::number(prices[5][index])));

        ui->TableBonds->update();
        ui->TableBonds->setShowGrid(false);
    }
    else
    {
        //QMessageBox::warning(this, "Внимание", "Биржа закрыта");
        ui->TableStocks->setItem(1,0,new QTableWidgetItem("Недоступно"));
        ui->TableStocks->setItem(1,1,new QTableWidgetItem("Недоступно"));
        ui->TableStocks->setItem(1,2,new QTableWidgetItem("Недоступно"));

        ui->TableBonds->setItem(1,0,new QTableWidgetItem("Недоступно"));
        ui->TableBonds->setItem(1,1,new QTableWidgetItem("Недоступно"));
        ui->TableBonds->setItem(1,2,new QTableWidgetItem("Недоступно"));
    }


}

void MainWindow::on_buy_clicked()
{
    investments->deleteInvestment("none");
    utils::addInvestmentFile(investments);
    int number = ui->ChooseCount->text().toInt();
    QString name = ui->ChoosePaper->currentText();
    double price = papers->getPriceByName(name);
    if(number > 0)
    {
        Investment *invest = new Investment(price * number, number, price, name);
        investments->addInvestment(*invest);
        utils::addInvestmentFile(investments);
        user->setNumberPapers(user->getNumberPapers() + number);
        utils::addUserDataToFile(user->getFirstName(),user->getLastName(),user->getProfitNow(),user->getMoneyBox(), user->getNumberPapers());
        QMessageBox::about(this, QString("Покупка ") + name, "Покупка произведена успешно");
    }
    else
    {
        QMessageBox::warning(this, QString("Покупка ") + name, "Недопустимое число бумаг для покупки");
    }

    on_update_clicked();
}
