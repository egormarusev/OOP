#ifndef ENTERSOURSES_H
#define ENTERSOURSES_H

#include <QLineEdit>
#include <QLabel>
#include <QDialog>
#include "collection.h"

namespace Ui {
class EnterSourses;
}

class EnterSourses : public QDialog
{
    Q_OBJECT

public:
    QList<QLineEdit *> lines;
    QList<QLabel *> labels;
    int p;
    Collection *collection = nullptr;
    explicit EnterSourses(QWidget *parent = nullptr, int p = 0, Collection *collection = nullptr);
    ~EnterSourses();

private slots:
    void on_enterSourses_clicked();

private:
    Ui::EnterSourses *ui;
};

#endif // ENTERSOURSES_H
