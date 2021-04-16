#ifndef SHOWSERIESWINDOW_H
#define SHOWSERIESWINDOW_H
#include "Collection.h"
#include <QDialog>

namespace Ui {
class ShowSeriesWindow;
}

class ShowSeriesWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ShowSeriesWindow(Video* ,QWidget *parent = nullptr);
    ~ShowSeriesWindow();

private slots:
    void on_OkButton_clicked();
    void on_CheckView_stateChanged(int arg1);

private:
    Ui::ShowSeriesWindow *ui;
    Video* serial;
};

#endif // SHOWSERIESWINDOW_H
