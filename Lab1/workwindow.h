#ifndef WORKWINDOW_H
#define WORKWINDOW_H
#include "collection.h"
#include <QDialog>

namespace Ui {
class WorkWindow;
}

class WorkWindow : public QDialog
{
    Q_OBJECT

public:
    Collection* collection = nullptr;
    explicit WorkWindow(QWidget *parent = nullptr, Collection *collection = nullptr);
    ~WorkWindow();

private slots:
    void on_enterElements_clicked();

    void on_enterConnection_clicked();

    void on_enterSourses_clicked();

    void on_enterFrequency_clicked();

    void on_findPotentials_clicked();

    void on_findFullResistance_clicked();

    void on_deleteAll_clicked();

    void on_exit_clicked();

    void on_SaveToFile_clicked();

private:
    Ui::WorkWindow *ui;
};

#endif // WORKWINDOW_H
