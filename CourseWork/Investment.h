#pragma once
#include <string>
#include <ctime>
#include <QString>
class Investment
{
private:
	double sum;
	int numberPapers;
    double price;
    QString paperName;

public:
    Investment(double sum = 0, int num = 0,double price = 0, QString paperName = " ");
	
	Investment(const Investment& other);
	~Investment();

	double getSum() const;
	int getNumberPapers() const;
    double getPrice() const;
    QString getPaperName() const;

	void setSum(double sum);
	void setNumberPapers(int num);
    void setPrice(double priceBuy);
    void setPaperName(QString paperName);

};

