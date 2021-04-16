#ifndef PQ_H
#define PQ_H

#include <QDialog>

namespace Ui {
class PQ;
}

class PQ : public QDialog
{
    Q_OBJECT

public:
    explicit PQ(QWidget *parent = nullptr);
    ~PQ();

private slots:
    void on_createNew_clicked();

private:
    Ui::PQ *ui;
};

#endif // PQ_H
