#ifndef ELEMENT_H
#define ELEMENT_H

const double defElementResistance = 0;
const int defNumber = 1;

enum class ElementType { R, LC };

class Element
{
protected:
    double elementResistance;
    int number;
    ElementType type;
public:
    //friend class Resistor;
    //friend class InductanceCapacitance;
    Element(double elementResistance = defElementResistance, int number = defNumber); // Конструктор по умолчанию elementResistance = 0,number = 1
    Element(const Element& other);
    virtual ~Element();

    void setElementResistance(double elementResistance);
    void setNumber(int number);

    double getElementResistance() const;
    int getNumber() const;
    ElementType getElementType() const;
    virtual void printParameters() const = 0;

    //virtual void printParameters() const = 0 ;
};

#endif // ELEMENT_H
