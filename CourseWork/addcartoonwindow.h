#ifndef ADDCARTOONWINDOW_H
#define ADDCARTOONWINDOW_H
#include "Collection.h"

#include <QDialog>

namespace Ui {
class AddCartoonWindow;
}

class AddCartoonWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddCartoonWindow(Collection*,QWidget *parent = nullptr);
    ~AddCartoonWindow();

private slots:
    void on_CancelButton_clicked();

    void on_AddButton_clicked();

private:
    Ui::AddCartoonWindow *ui;
    Collection *collection;
    void check_str_field();
    void check_year_field();
    void check_rating_field();
    void check_button_add();


};

#endif // ADDCARTOONWINDOW_H
