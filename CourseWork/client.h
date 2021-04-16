#ifndef CLIENT_H
#define CLIENT_H

#include <QDialog>
#include "User.h"
#include "BoughtCollection.h"

namespace Ui {
class Client;
}

class Client : public QDialog
{
    Q_OBJECT

public:
    User *user;
    BoughtCollection* investments;
    PaperCollection* papers;
    explicit Client(QWidget *parent = nullptr, User* user = nullptr, BoughtCollection* investments = nullptr, PaperCollection* papers = nullptr);
    ~Client();

private slots:
    void on_backToMarket_clicked();

    void on_informationChanged_clicked();

    void on_update_clicked();

    void on_myInvestment_clicked();

private:
    Ui::Client *ui;
};

#endif // CLIENT_H
