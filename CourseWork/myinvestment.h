#ifndef MYINVESTMENT_H
#define MYINVESTMENT_H

#include <QDialog>
#include "BoughtCollection.h"
#include "User.h"

namespace Ui {
class MyInvestment;
}

class MyInvestment : public QDialog
{
    Q_OBJECT

public:
    BoughtCollection *investments;
    User* user;
    PaperCollection* papers;
    explicit MyInvestment(QWidget *parent = nullptr, BoughtCollection *investments = nullptr, User* user = nullptr, PaperCollection* papers = nullptr);
    ~MyInvestment();

private slots:
    void on_sell_clicked();

    void on_backToCabinet_clicked();

    void on_update_clicked();

private:
    Ui::MyInvestment *ui;
};

#endif // MYINVESTMENT_H
