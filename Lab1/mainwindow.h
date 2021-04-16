#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_createNew_clicked();

    void on_exit_clicked();

    void on_downloadOne_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
