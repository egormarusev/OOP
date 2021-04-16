#include "PaperCollection.h"
#include <iostream>
#include <cstring>
#include "SecurityPaper.h"
#include <QVector>

PaperCollection::PaperCollection()
{
    this->papers.reserve(98);
	this->count = 0;
}

PaperCollection::~PaperCollection()
{

}

void PaperCollection::addPaper(SecurityPaper* paper)
{
    this->papers << paper;
    count++;
}

int PaperCollection::getCount() const
{
	return this->count;
}

SecurityPaper PaperCollection::getPaper(QString name) const
{
    int n = this->getCount();
    SecurityPaper *paper;
    for(int i = 0;i < n; i++)
    {
        if(papers.at(i)->getName() == name)
        {
            paper = new SecurityPaper(*papers.at(i));
        }
    }
    return *paper;
}
SecurityPaper PaperCollection::getPaper(int index) const
{
    if (index >= 0 && index <= count )
    {
        return *papers[index];
    }
    else
    {
        std::cout << "Not enough papers.\n";
        exit(1);
    }
}

void PaperCollection::setPrice(QString name, double sum)
{
	for (int i = 0; i < count; i++)
	{
        if (papers[i]->getName()== name)
		{
			papers[i]->setPrice(sum);
		}
	}
}

double PaperCollection::getPriceByName(QString name)const
{
    int n = this->getCount();
    int s = 0;
    for(int i = 0;i < n; i++)
    {
        if(papers.at(i)->getName() == name)
            s = papers.at(i)->getPrice();
    }
    return s;
}

