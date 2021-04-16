#pragma once
#include "SecurityPaper.h"
#include <QVector>
#include <QList>

class PaperCollection
{
private:
    QVector <SecurityPaper*> papers;
	int count;

public:
	PaperCollection();
	~PaperCollection();

	int getCount() const;
    SecurityPaper getPaper(QString name) const;
    SecurityPaper getPaper(int index) const;
    double getPriceByName(QString name)const;

    void setPrice(QString name, double sum);

    void addPaper(SecurityPaper* paper);
	void deletePaper(int n);
};

