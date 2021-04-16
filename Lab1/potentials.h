#ifndef POTENTIALS_H
#define POTENTIALS_H

#include <QDialog>
#include "collection.h"
#include <QLineEdit>
#include <QLabel>

namespace Ui {
class Potentials;
}

class Potentials : public QDialog
{
    Q_OBJECT

public:
    int q;
    QList<QLineEdit *> lines;
    QList<QLabel *> labels;
    Collection *collection = nullptr;
    explicit Potentials(QWidget *parent = nullptr, Collection *collection = nullptr, int q =0);
    ~Potentials();

private slots:
    void on_Ok_clicked();

private:
    Ui::Potentials *ui;
};

#endif // POTENTIALS_H
