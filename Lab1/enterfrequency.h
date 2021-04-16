#ifndef ENTERFREQUENCY_H
#define ENTERFREQUENCY_H

#include <QDialog>
#include "collection.h"

namespace Ui {
class EnterFrequency;
}

class EnterFrequency : public QDialog
{
    Q_OBJECT

public:
    Collection *collection = nullptr;
    explicit EnterFrequency(QWidget *parent = nullptr, Collection *collection = nullptr);
    ~EnterFrequency();

private slots:
    void on_enterFrequency_clicked();

private:
    Ui::EnterFrequency *ui;
};

#endif // ENTERFREQUENCY_H
