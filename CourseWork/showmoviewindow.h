#ifndef SHOWMOVIEWINDOW_H
#define SHOWMOVIEWINDOW_H
#include "Collection.h"
#include <QDialog>

namespace Ui {
class ShowMovieWindow;
}

class ShowMovieWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ShowMovieWindow(Video* ,QWidget *parent = nullptr);
    ~ShowMovieWindow();

private slots:
    void on_OkButton_clicked();
    void on_CheckView_stateChanged(int arg1);

private:
    Video* film;
    Ui::ShowMovieWindow *ui;
};

#endif // SHOWMOVIEWINDOW_H
