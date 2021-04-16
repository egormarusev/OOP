#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "User.h"
#include "PaperCollection.h"
#include "BoughtCollection.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    User *user;
    PaperCollection *papers;
    BoughtCollection *investments;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_showGraphic_clicked();

    void on_ClientMenu_clicked();

    void on_update_clicked();

    void on_buy_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
