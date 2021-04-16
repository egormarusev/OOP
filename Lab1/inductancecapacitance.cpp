#include "inductancecapacitance.h"

#include <iostream>

InductanceCapacitance::InductanceCapacitance(double reactiveResistance, int number)
{
    setNumber(number);
    setElementResistance(reactiveResistance);
    type = ElementType::LC;
}

InductanceCapacitance::InductanceCapacitance(const InductanceCapacitance& other)
{
    setNumber(other.getNumber());
    setElementResistance(other.getElementResistance());
    type = ElementType::LC;
}

InductanceCapacitance::InductanceCapacitance(const Element& other)
{
    setNumber(other.getNumber());
    setElementResistance(other.getElementResistance());
    type = ElementType::LC;
}

InductanceCapacitance::~InductanceCapacitance()
{
}

void InductanceCapacitance::printParameters() const
{
    std::cout << "Number of LC element: " << getNumber() << std::endl;
    std::cout << "Reactive Resistance of LC element: " << getElementResistance() << std::endl;
}

