#ifndef ADDMOVIEWINDOW_H
#define ADDMOVIEWINDOW_H
#include "Collection.h"

#include <QDialog>

namespace Ui {
class AddMovieWindow;
}

class AddMovieWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddMovieWindow(Collection*,QWidget *parent = nullptr);
    ~AddMovieWindow();

private slots:
    void on_CancelButton_clicked();

    void on_AddButton_clicked();

private:
    Ui::AddMovieWindow *ui;
    Collection *collection;
    void check_str_field();
    void check_year_field();
    void check_rating_field();
    void check_button_add();


};

#endif // ADDMOVIEWINDOW_H
