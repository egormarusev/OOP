#include "element.h"
#include <iostream>

Element::Element(double resistance, int number)
{
    setNumber(number);
    setElementResistance(resistance);
}

Element::Element(const Element& other)
{
    setNumber(other.getNumber());
    setElementResistance(other.getElementResistance());
}

Element::~Element()
{
}

void Element::setElementResistance(double elementResistance)
{
    if (elementResistance <= 0)
        this->elementResistance = defElementResistance;
    else
        this->elementResistance = elementResistance;
}

void Element::setNumber(int number)
{
    if (number <= 0)
        this->number = defNumber;
    else
        this->number = number;

}

double Element::getElementResistance() const
{
    return this->elementResistance;
}

int Element::getNumber() const
{
    return this->number;
}

ElementType Element::getElementType() const
{
    return type;
}

