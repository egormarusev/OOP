#ifndef DELETEVIDEO_H
#define DELETEVIDEO_H

#include <QDialog>
#include "Collection.h"

namespace Ui {
class deletevideo;
}

class deletevideo : public QDialog
{
    Q_OBJECT

public:
    explicit deletevideo(Collection *collection, QWidget *parent = nullptr);
    ~deletevideo();

private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    Collection *collection;
    Ui::deletevideo *ui;
};

#endif // DELETEVIDEO_H
