#pragma once
#include <QString>
class User
{
private:
	double profitNow;
	double moneyBox;
    QString firstName;
    QString lastName;
    int numberPapers;

public:
    User(QString firstName = "Name", QString lastName = "lastName", double profit = 0, double moneyBox = 0, int numberPapers = 0);
	~User();

	double getProfitNow();
	double getMoneyBox();
    QString getFirstName();
    QString getLastName();
    int getNumberPapers();

	void setProfitNow(double profit);
	void addToMoneyBox(double sum);
    void setFirstName(QString firstName);
    void setMoneyBox(double moneyBox);
    void setLastName(QString lastName);
    void setNumberPapers(int numberPapers);
};

