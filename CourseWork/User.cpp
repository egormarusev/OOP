#include "User.h"
#include <iostream>

User::User(QString firstName, QString lastName, double profit, double moneyBox, int numberPapers)
{
    this->setFirstName(firstName);
    this->setLastName(lastName);
    this->setProfitNow(profit);
    this->setMoneyBox(moneyBox);
    this->setNumberPapers(numberPapers);
}

User::~User()
{
}

double User::getProfitNow()
{
	return this->profitNow;
}

double User::getMoneyBox()
{
	return this->moneyBox;
}

QString User::getFirstName()
{
	return this->firstName;
}

QString User::getLastName()
{
	return this->lastName;
}
int User::getNumberPapers()
{
   return this->numberPapers;
}

void User::setProfitNow(double profit)
{
	this->profitNow = profit;
}

void User::addToMoneyBox(double sum)
{
	this->moneyBox += sum;
}

void User::setMoneyBox(double moneyBox)
{
    this->moneyBox = moneyBox;
}

void User::setFirstName(QString firstName)
{
	this->firstName = firstName;
}

void User::setLastName(QString lastName)
{
	this->lastName = lastName;
}
void User::setNumberPapers(int numberPapers)
{
    this->numberPapers = numberPapers;
}

