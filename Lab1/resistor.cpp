#include "resistor.h"
#include <iostream>

Resistor::Resistor(double ElementResistance, int number)
{
    setNumber(number);
    setElementResistance(ElementResistance);
    type = ElementType::R;
}

Resistor::Resistor(const Resistor& other)
{
    setNumber(other.getNumber());
    setElementResistance(other.getElementResistance());
    type = ElementType::R;
}

Resistor::Resistor(const Element& other)
{
    setNumber(other.getNumber());
    setElementResistance(other.getElementResistance());
    type = ElementType::R;
}

Resistor::~Resistor()
{
}

void Resistor::printParameters() const
{
    std::cout << "Number of Resistor: " << getNumber() << std::endl;
    std::cout << "Resistance of R element: " << getElementResistance() << std::endl;
}
