#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QDialog>
#include "qcustomplot.h"

namespace Ui {
class Graphics;
}

class Graphics : public QDialog
{
    Q_OBJECT

public:
    int index;
    explicit Graphics(QWidget *parent = nullptr, int index = 0);
    ~Graphics();

private slots:
    void slotRangeChanged (const QCPRange &newRange);

private:
    Ui::Graphics *ui;
    QCustomPlot *customPlot;    // Объявляем графическое полотно
    QCPGraph *graphic;
};

#endif // GRAPHICS_H
