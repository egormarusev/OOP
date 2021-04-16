#ifndef INDUCTANCECAPACITANCE_H
#define INDUCTANCECAPACITANCE_H


#pragma once
#include "element.h"

class InductanceCapacitance : public Element
{
public:
    InductanceCapacitance(double ElementResistance = defElementResistance, int number = defNumber);
    InductanceCapacitance(const InductanceCapacitance& other);
    InductanceCapacitance(const Element& other);
    virtual ~InductanceCapacitance();
    virtual void printParameters() const;
};
#endif // INDUCTANCECAPACITANCE_H
