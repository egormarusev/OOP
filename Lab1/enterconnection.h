#ifndef ENTERCONNECTION_H
#define ENTERCONNECTION_H

#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include "collection.h"

namespace Ui {
class EnterConnection;
}

class EnterConnection : public QDialog
{
    Q_OBJECT

public:
    QList<QComboBox *> lines;
    QList<QLabel *> labels;
    Collection *collection = nullptr;
    int p = 0;
    int q = 0;
    explicit EnterConnection(QWidget *parent = nullptr, int p = 0, int q = 0, Collection *collection = nullptr);
    ~EnterConnection();

private slots:
    void on_enterConnection_clicked();

private:
    Ui::EnterConnection *ui;
};

#endif // ENTERCONNECTION_H
