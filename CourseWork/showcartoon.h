#ifndef SHOWCARTOONWINDOW_H
#define SHOWCARTOONWINDOW_H
#include "Collection.h"
#include <QDialog>

namespace Ui {
class ShowCartoonWindow;
}

class ShowCartoonWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ShowCartoonWindow(Video* ,QWidget *parent = nullptr);
    ~ShowCartoonWindow();

private slots:
    void on_OkButton_clicked();
    void on_CheckView_stateChanged(int arg1);

private:
    Video* film;
    Ui::ShowCartoonWindow *ui;
};

#endif // SHOWCARTOONWINDOW_H
