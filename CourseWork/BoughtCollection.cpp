#include "BoughtCollection.h"
#include <iostream>
#include <cstring>

BoughtCollection::BoughtCollection(PaperCollection* papers, User* user)
{
	this->count = 0;
    this->investments.reserve(100);

	this->papers = papers;
	this->user = user;
}

BoughtCollection::~BoughtCollection()
{

}

void BoughtCollection::addInvestment(const Investment& invest)
{
    QString name =  invest.getPaperName();
    bool flag = false;
    int index = 0;
    for(int i = 0; i<count;i++)
    {
        if(this->investments.at(i)->getPaperName() == name)
        {
            flag = true;
            index = i;
        }
    }
    if(flag)
    {
        double newPrice = invest.getPrice();
        double newSum = invest.getSum() + investments.at(index)->getSum();
        int newNumber = invest.getNumberPapers() + investments.at(index)->getNumberPapers();
        this->setInvestmentByName(newPrice,newSum,newNumber,name);

    }
    else
    {
        investments.push_back(new Investment(invest));
        count+=1;
    }
}

int BoughtCollection::getCount() const
{
	return this->count;
}

Investment BoughtCollection::getInvestment(int index) const
{
	if (index < 0 || index >= count )
	{
		std::cout << "Not enough investments.\n";
        exit(1);
		index = 0;
	}
	return *investments[index];
}


void BoughtCollection::sellInvestment(QString name, int number)
{
	double pricePaperNow = 0;
	for (int i = 0; i < papers->getCount(); i++)
	{
        if (papers->getPaper(i).getName()== name)
		{
            pricePaperNow = papers->getPaper(i).getPrice();
		}
	}

	for (int i = 0; i < count; i++)
	{
        if (investments[i]->getPaperName()== name)
		{
			int nPapersBefore = investments[i]->getNumberPapers();
			int sumBefore = investments[i]->getSum();
			if (nPapersBefore > number)
			{
				investments[i]->setNumberPapers(nPapersBefore - number);
				//BoughtInvestments[i]->setPriceOnTheMomentSale(pricePaperNow);
				investments[i]->setSum(sumBefore - (pricePaperNow * number));
			}
			else if(nPapersBefore == number)
			{
				deleteInvestment(i);
			}
		}
	}

	user->addToMoneyBox(pricePaperNow * number);

}

void BoughtCollection::deleteInvestment(int index)
{
    investments.erase(investments.begin() + index);
    this->count-=1;
}

void BoughtCollection::profit()
{
	double sumBuy = 0;
	for (int i = 0; i < count; i++)
	{
		sumBuy += investments[i]->getSum();
	}

	double sumNow = 0;
	for (int i = 0; i < count; i++)
	{
        QString name = investments[i]->getPaperName();
		for (int j = 0; j < papers->getCount(); j++)
		{
            if (papers->getPaper(j).getName()== name)
			{
                sumNow += papers->getPaper(j).getPrice();
			}
		}
	}

    if(sumBuy != 0)
        user->setProfitNow(sumNow - sumBuy);
    else
        user->setProfitNow(0);
}

int BoughtCollection::getNumberInvesments(QString name)const
{
    int k = 0;
    for(int i = 0;i < count; i++)
    {
        if(investments.at(i)->getPaperName() == name)
            k = investments.at(i)->getNumberPapers();
    }
    return k;
}

void BoughtCollection::setInvestments(QVector<QStringList> data)
{
    int n = data.size();
    double sum = 0;
    int num = 0;
    double price = 0;
    QString name;
    for(int i = 0; i < n; i++)
    {
        sum = data.at(i).at(0).toDouble();
        num = data.at(i).at(1).toInt();
        price = data.at(i).at(2).toDouble();
        name = data.at(i).at(3);
        Investment *inv = new Investment(sum, num,price, name);
        this->addInvestment(*inv);
    }
}

void BoughtCollection::deleteInvestment(QString name)
{
    for(int i = 0;i < count; i++)
    {
        if(investments.at(i)->getPaperName() == name)
        {
            investments.erase(investments.begin() + i);
            this->count-=1;
        }
    }
}

void BoughtCollection::setInvestmentByName(double price, double sum, int number, QString name)
{
    for(int i = 0;i < count; i++)
    {
        if(investments.at(i)->getPaperName() == name)
        {
            investments.at(i)->setSum(sum);
            investments.at(i)->setPaperName(name);
            investments.at(i)->setPrice(price);
            investments.at(i)->setNumberPapers(number);
        }
    }
}
void BoughtCollection::setCountInvestment(int num)
{
    this->count = num;
}

bool BoughtCollection::checkHaveInvestmentByName(QString name)
{
    bool flag = false;
    for(int i = 0;i < count; i++)
    {
        if(investments.at(i)->getPaperName() == name)
        {
            flag = true;
        }

    }
    return flag;
}

Investment BoughtCollection::getInvestment(QString name) const
{
    Investment* inv;
    for(int i = 0;i < count; i++)
    {
        if(investments.at(i)->getPaperName() == name)
            inv = investments.at(i);
    }
    return *inv;
}

