#include "SecurityPaper.h"

SecurityPaper::SecurityPaper(QString name, double price)
{
	setName(name);
	setPrice(price);
}
SecurityPaper::SecurityPaper(SecurityPaper &other)
{
    setName(other.getName());
    setPrice(other.getPrice());
}


SecurityPaper::~SecurityPaper()
{
}

QString SecurityPaper::getName()
{
	return this->name;
}


double SecurityPaper::getPrice()
{
	return this->price;
}


void SecurityPaper::setName(QString name)
{
	this->name = name;
}

void SecurityPaper::setPrice(double price)
{
	this->price = price;
}

