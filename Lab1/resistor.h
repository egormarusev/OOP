#ifndef RESISTOR_H
#define RESISTOR_H


#include "element.h"

class Resistor : public Element
{
public:
    Resistor(double ElementResistance = defElementResistance, int number = defNumber);
    Resistor(const Resistor& other);
    Resistor(const Element& other);
    virtual ~Resistor();
    virtual void printParameters() const;
};


#endif // RESISTOR_H
