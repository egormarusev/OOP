
#include "Investment.h"

Investment::Investment(double sum, int num, double price, QString name)
        
{
    setSum(sum);
    setNumberPapers(num);
    setPrice(price);
    setPaperName(name);
}
	
Investment::Investment(const Investment& other)
{
    setSum(other.getSum());
    setNumberPapers(other.getNumberPapers());
    setPrice(other.getPrice());
    setPaperName(other.getPaperName());
}

Investment::~Investment()
{

}
//------------------------------------------------------------------------------------------------------------------
double Investment::getSum() const
{
    return this->sum;
}
int Investment::getNumberPapers() const
{
    return this->numberPapers;
}
double Investment::getPrice() const
{
    return this->price;
}

QString Investment::getPaperName() const
{
    return this->paperName;
}
//------------------------------------------------------------------------------------------------------------------

void Investment::setSum(double sum)
{
    this->sum = sum;
}
void Investment::setNumberPapers(int num)
{
    this->numberPapers = num;
}
void Investment::setPrice(double priceBuy)
{
    this->price = priceBuy;
}

void Investment::setPaperName (QString paperName)
{
    this->paperName = paperName;
}

//-------------------------------------------------------------------------------------------------------------------
