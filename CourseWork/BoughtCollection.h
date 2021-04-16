#pragma once
#include "Investment.h"
#include "PaperCollection.h"
#include "User.h"
class BoughtCollection
{
private:
    QVector<Investment*> investments;
	int count;
	PaperCollection *papers;
	User *user;


public:
	BoughtCollection(PaperCollection* papers, User* user);
	~BoughtCollection();

	int getCount() const;
    Investment getInvestment(int index) const;
    Investment getInvestment(QString name) const;
    int getNumberInvesments(QString name) const;

    void deleteInvestment(int n);
    void deleteInvestment(QString name);

    void setInvestments(QVector<QStringList> data);
    void setInvestmentByName(double price, double sum, int number, QString name);
    void setCountInvestment(int num);

	void addInvestment(const Investment& invest);
    void sellInvestment(QString name, int number);
	void profit();
    bool checkHaveInvestmentByName(QString name);
};

