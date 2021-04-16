#ifndef FULLRESISTANCE_H
#define FULLRESISTANCE_H

#include <QDialog>
#include "collection.h"

namespace Ui {
class FullResistance;
}

class FullResistance : public QDialog
{
    Q_OBJECT

public:
    Collection *collection = nullptr;
    explicit FullResistance(QWidget *parent = nullptr, Collection *collection = nullptr);
    ~FullResistance();

private slots:
    void on_EnterNumbers_clicked();

    void on_Exit_clicked();

private:
    Ui::FullResistance *ui;
};

#endif // FULLRESISTANCE_H
