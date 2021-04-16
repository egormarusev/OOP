#pragma once
#include <string>
#include "Investment.h"
#include <QString>

class SecurityPaper
{
private:
    QString name;
	double price;

public:
    SecurityPaper(QString name = "Paper", double price = 0);
    SecurityPaper(SecurityPaper &other);
	~SecurityPaper();

    QString getName();
	double getPrice();

    void setName(QString name);
	void setPrice(double price);
};
