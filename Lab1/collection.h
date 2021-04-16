#ifndef COLLECTION_H
#define COLLECTION_H


#pragma once
#include "resistor.h"
#include <fstream>
#include "inductancecapacitance.h"

class Collection
{
private:
    Element*** collection;
    int p;
    int q;
    double frequency;
    double* currentSourse;
    double* powerSourse;
    double** connection;
    double* nodalPotentials;

    void setSize(const int p,const int q);
    void setNodalPotentials(double* U0);

public:
    Collection();
    Collection(const int p, const int q);
    Collection(const Collection& other);
    ~Collection();

    int getNumberRibs()const;
    int getNumberNodes()const;
    void deleteAll();

    void printCollection()const;
    void printConnection()const;

    Resistor getElementR(const int n, const int m)const;
    InductanceCapacitance getElementLC(const int n, const int m)const;
    Element& getElement(const int n, const int m)const;
    void getCollection(Element*** A)const;
    double* getCurrentSourse()const;
    double* getPowerSourse()const;
    double getFrequency()const;
    double* getNodalPotentials()const;
    double** getConnection()const;
    double getCountElements()const;

    void setCollection(Element*** elements);
    void setCurrentSourse(double* currentSourse);
    void setPowerSourse(double* powerSourse);
    void setConnection(double** connection);
    void setFrequency(double f);

    void fgetData(std::ifstream& file);
    void fprintData(std::ofstream& file);
    void solvePotentials();
    double solveFullResistance(int numberR, int numberLC);
};

#endif // COLLECTION_H
