#ifndef ADDSERIESWINDOW_H
#define ADDSERIESWINDOW_H
#include "Collection.h"
#include <QDialog>

namespace Ui {
class AddSeriesWindow;
}

class AddSeriesWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddSeriesWindow(Collection*, QWidget *parent = nullptr);
    ~AddSeriesWindow();

private slots:
    void on_CancelButton_clicked();

    void on_AddButton_clicked();

private:
    Ui::AddSeriesWindow *ui;
    Collection *collection;
    void check_button_add();
};

#endif // ADDSERIESWINDOW_H
