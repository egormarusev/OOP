#ifndef ENTERELEMENTS_H
#define ENTERELEMENTS_H

#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include "collection.h"

namespace Ui {
class EnterElements;
}

class EnterElements : public QDialog
{
    Q_OBJECT

public:
    QList<QLineEdit *> lines;
    QList<QLabel *> labels;
    int p;
    Collection *collection = nullptr;
    explicit EnterElements(QWidget *parent = nullptr, int p = 0, Collection *collection = nullptr);
    ~EnterElements();

private slots:
    void on_enterElements_clicked();

private:
    Ui::EnterElements *ui;
};

#endif // ENTERELEMENTS_H
