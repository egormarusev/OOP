#include "collection.h"
#include "resistor.h"
#include "element.h"
#include "inductancecapacitance.h"
#include "utils.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <QtMath>


Collection::Collection(const int p, const int q)
{
    if (p > 0 && q > 0)
    {
        collection = new Element **[2];
        for (int i = 0; i < 2; i++)
        {
            collection[i] = new Element *[p];
            for (int j = 0; j < p; j++)
                if (i == 0)
                {
                    collection[i][j] = new Resistor();
                }
                else
                {
                    collection[i][j] = new InductanceCapacitance();
                }
        }

        currentSourse = new double[p];
        for (int i = 0; i < p; i++)
            currentSourse[i] = 0;

        powerSourse = new double[p];
        for (int i = 0; i < p; i++)
            powerSourse[i] = 0;

        connection = new double* [q-1];
        for (int i = 0; i < q-1; i++)
        {
            connection[i] = new double[p];
            for (int j = 0; j < p; j++)
                connection[i][j] = 0;
        }

        nodalPotentials = new double[q-1];
        for (int i = 0; i < q-1; i++)
            nodalPotentials[i] = 0;

        this->p = p;
        this->q = q;
        this->frequency = 0;
    }
    else
    {
        exit(1);
        std::cout << "The index is wrong.\n";
    }
}

Collection::Collection(const Collection& other)
{
    int p = other.getNumberRibs();
    int q = other.getNumberNodes();
    if (p > 0 && q > 0)
    {
        collection = new Element ** [2];
        for (int i = 0; i < p; i++)
        {
            collection[i] = new Element*[p];
            for (int j = 0; j < p; j++)
                collection[i][j] = other.collection[i][j];
        }

        currentSourse = new double[p];
        for (int i = 0; i < p; i++)
            currentSourse[i] = other.currentSourse[i];

        powerSourse = new double[p];
        for (int i = 0; i < p; i++)
            powerSourse[i] = other.powerSourse[i];

        connection = new double* [p];
        for (int i = 0; i < p; i++)
        {
            connection[i] = new double[q - 1];
            for (int j = 0; j < q - 1; j++)
                connection[i][j] = other.connection[i][j];
        }

        nodalPotentials = new double[q - 1];
        for (int i = 0; i < q - 1; i++)
            nodalPotentials[i] = other.nodalPotentials[i];

        this->p = p;
        this->q = q;
    }
    else
        std::cout << "The index is wrong.\n";
}

Collection::~Collection()
{
    if (p > 0 && q > 0)
    {

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < p; j++)
            {
                delete collection[i][j];
            }
            delete[] collection[i];
        }
        delete[] collection;

        delete[] currentSourse;

        delete[] powerSourse;

        for (int i = 0; i < q - 1; i++)
            delete[] connection[i];

        delete[] connection;

        delete[] nodalPotentials;
    }

}

void Collection::setSize(const int p, const int q)
{
    this->p = p;
    this->q = q;
}

int Collection::getNumberRibs() const
{
    return this->p;
}

int Collection::getNumberNodes() const
{
    return this->q;
}

void Collection::deleteAll()
{
     if (p >0 && q>0)
    {
         for (int i = 0; i < 2; i++)
         {
             for (int j = 0; j < p; j++)
             {
                 delete collection[i][j];
             }
             delete[] collection[i];
         }
         delete collection;

        delete[] currentSourse;

        delete[] powerSourse;

        for (int i = 0; i < q - 1; i++)
            delete[] connection[i];

        delete[] connection;

        delete[] nodalPotentials;
    }
    this->p = 0;
    this->q = 0;
    this->frequency = 0;
    std::cout << "All records were deleted.\n";
}

void Collection::printCollection() const
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < p; j++)
        {
            std::cout << collection[i][j]->getElementResistance()<< " " ;
        }
        std::cout << "\n";
    }
}

void Collection::printConnection() const
{
    for (int i = 0; i < q-1; i++)
    {
        for (int j = 0; j < p; j++)
        {
            std::cout << connection[i][j]<< " ";
        }
        std::cout << "\n";
    }
}

Resistor Collection::getElementR(const int n, const int m) const
{
    if (n < 0 || m < 0)
    {
        std::cout << "The index is wrong.\n";
        throw 1;
    }
    else
    {
        return *(collection)[n][m];
    }
}

InductanceCapacitance Collection::getElementLC(const int n, const int m) const
{
    if (n < 0 || m < 0)
    {
        std::cout << "The index is wrong.\n";
        throw 1;
    }
    else
    {
        return *(collection)[n][m];
    }
}


Element& Collection::getElement(const int n, const int m) const
{
    if (n < 0 || m < 0)
    {
        std::cout << "The index is wrong.\n";
        throw 1;
    }
    else
    {
        return *(collection)[n][m];
    }
}

void Collection::getCollection(Element*** A) const
{
    A = new Element **[2];
    for (int i = 0; i < 2; i++)
    {
        A[i] = new Element*[p];
        for (int j = 0; j < p; j++)
            A[i][j] = &this->getElement(i, j);
    }
}

double* Collection::getCurrentSourse() const
{
    double* A = new double [p];
    for (int i = 0; i < p; i++)
    {
        A[i] = currentSourse[i];
    }
    return A;
}

double* Collection::getPowerSourse() const
{
    double* A = new double[p];
    for (int i = 0; i < p; i++)
    {
        A[i] = powerSourse[i];
    }
    return A;
}

double** Collection::getConnection() const
{
    double** A = new double * [q-1];
    for (int i = 0; i < q-1; i++)
    {
        A[i] = new double[p];
        for (int j = 0; j < p; j++)
            A[i][j] = connection[i][j];
    }
    return A;
}

double Collection::getFrequency()const
{
    return this->frequency;
}
double* Collection::getNodalPotentials()const
{
    double* A = new double[q-1];
    for (int i = 0; i < q-1; i++)
    {
        A[i] = nodalPotentials[i];
    }
    return A;
}


void Collection::setCollection(Element ***elements)
{

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < p; j++)
        {
            if (elements[i][j]->getElementType() == ElementType::R)
            {
                Resistor* r = new Resistor(*elements[i][j]);
                delete this->collection[i][j];
                this->collection[i][j] = r;
            }
            else
            {
                InductanceCapacitance* lc = new InductanceCapacitance(*elements[i][j]);
                delete this->collection[i][j];
                this->collection[i][j] = lc;
            }
        }
    }

}

void Collection::setCurrentSourse(double* currentSourse)
{
    for (int i = 0; i < p; i++)
    {
        this->currentSourse[i] = currentSourse[i];
    }
}

void Collection::setPowerSourse(double* powerSourse)
{
    for (int i = 0; i < p; i++)
    {
        this->powerSourse[i] = powerSourse[i];
    }
}

void Collection::setConnection(double** connection1)
{
    for (int i = 0; i < q-1; i++)
    {
        for (int j = 0; j < p; j++)
            connection[i][j] = connection1[i][j];
    }
}

void Collection::setNodalPotentials(double* U0)
{
    for (int i = 0; i < p; i++)
    {
        this->nodalPotentials[i] = U0[i];
    }
}

void Collection::setFrequency(double f)
{
    this->frequency = f;
}

double Collection::getCountElements() const
{
    return 0;
}

void Collection::fgetData(std::ifstream& file)
{
    std::string buffer;
    std::string resistance;
    std::string lc;
    std::string connection;
    std::string currentSourse;
    std::string powerSourse;
    std::string  pq;
    int count = 0;
    while (!file.eof())
    {
        count++;
        getline(file, buffer);
        if (count == 1)
            pq = buffer;
        if (count == 2)
            resistance = buffer;
        if (count == 3)
            lc = buffer;
        if (count == 4)
            connection = buffer;
        if (count == 5)
            currentSourse = buffer;
        if (count == 6)
            powerSourse = buffer;
    }
    double* resistanceM;
    double* lcM;
    double* connectionM;
    double* currentSourseM;
    double* powerSourseM;

    int* pqM = new int[2];
    pqM[0] = 0;
    utils::parseStr(pq, pqM); // Получение полей для записи из файла
    int p = pqM[0];
    int q = pqM[1];
    this->setSize(pqM[0], pqM[1]);
    delete[] pqM;

    resistanceM = new double[p];
    utils::parseStr(resistance, resistanceM);
    lcM = new double[p];
    utils::parseStr(lc, lcM);
    Element*** elements = utils::RLCtoCollection(resistanceM, lcM, p);
    this->setCollection(elements);
    utils::cleanMemory(elements, 2, p);
    delete []resistanceM;
    delete []lcM;

    connectionM = new double[p * (q - 1)];
    utils::parseStr(connection, connectionM);
    double** connectionConvert = utils::convertConnectionM(connectionM, p, q);
    this->setConnection(connectionConvert);
    delete []connectionM;
    utils::cleanMemory(connectionConvert, q-1);

    currentSourseM = new double[p];
    utils::parseStr(currentSourse, currentSourseM);
    this->setCurrentSourse(currentSourseM);
    delete []currentSourseM;

    powerSourseM = new double[p];
    utils::parseStr(powerSourse, powerSourseM);
    this->setPowerSourse(powerSourseM);
    delete []powerSourseM;
}

void Collection::fprintData(std::ofstream& file)
{
    file << p << " " << q << " \n";

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < p; j++)
        {
            if ((*collection)[i][j].getElementType() == ElementType::R)
            {
                if (j < p - 1)
                {
                    file << (*collection)[i][j].getElementResistance() << " ";
                }
                else
                {
                    file << (*collection)[i][j].getElementResistance() << " \n";
                }
            }
        }
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < p; j++)
        {
            if ((*collection)[i][j].getElementType() == ElementType::LC)
            {
                if (j < p - 1)
                {
                    file << collection[i][j]->getElementResistance() << " ";
                }
                else
                {
                    file << collection[i][j]->getElementResistance() << " \n";
                }
            }
        }
    int n = 0;
    for (int i = 0; i < q - 1; i++)
        for (int j = 0; j < p; j++)
        {
            if (n != p * (q - 1) - 1)
                file << connection[i][j] << " ";
            else
                file << connection[i][j] << " \n";
            n++;
        }

    for (int i = 0; i < p; i++)
    {
        if (i < p - 1)
            file << currentSourse[i] << " ";
        else
            file << currentSourse[i] << " \n";
    }

    for (int i = 0; i < p; i++)
    {
        if (i < p - 1)
            file << powerSourse[i] << " ";
        else
            file << powerSourse[i] << " \n";
    }
/*
    for (int i = 0; i < q-1; i++)
    {
        if (i < q - 2)
            file << nodalPotentials[i] << " ";
        else
            file << nodalPotentials[i] << " \n";
    }
*/

}

void Collection::solvePotentials()
{
    double** A = utils::clone(this->connection,q-1,p);

    double** Y = utils::CollectionToY(this->collection, p);

    double** I = utils::transposeMasive(currentSourse, p);

    double** E = utils::transposeMasive(powerSourse, p);

    //------------------------------------------------------

    double** AY = utils::multM(A, q - 1, p, Y, p, p);

    double** At = utils::transpose(A, q - 1, p);

    double** AYAt = utils::multM(AY, q - 1, p, At, p, q - 1);

    double** YE = utils::multM(Y, p, p, E, p, 1);

    double** IYE = utils::sumM(I, p, 1, YE, p, 1);

    double** AIYE = utils::multM(A, q - 1, p, IYE, p, 1);

    double** _AIYE = utils::multScalar(AIYE, q - 1, 1, -1);

    double** AYAt1 =  utils::inversion(AYAt, q - 1);

    double** U0 = utils::multM(AYAt, q - 1, q - 1, _AIYE, q - 1, 1);

    double* Potentials = utils::makeMassiveU0(U0, q - 1);

    this->setNodalPotentials(Potentials);

    //-------------------------------------------------------

    utils::cleanMemory(A, q - 1);
    utils::cleanMemory(Y, p);
    utils::cleanMemory(I, p);
    utils::cleanMemory(E, p);
    utils::cleanMemory(AY, q-1);
    utils::cleanMemory(At, p);
    utils::cleanMemory(AYAt, q-1);
    utils::cleanMemory(YE, p);
    utils::cleanMemory(IYE, p);
    utils::cleanMemory(AIYE, q-1);
    utils::cleanMemory(_AIYE, q - 1);
    utils::cleanMemory(AYAt1, q - 1);
    utils::cleanMemory(U0, q - 1);

    delete[] Potentials;

}

double Collection::solveFullResistance(int numberR, int numberLC)
{
    if (numberR <= p && numberLC <= p)
    {
        int R = collection[0][numberR]->getElementResistance();
        int X = collection[1][numberLC]->getElementResistance();
        int Z = sqrt(R*R + X*X);
        return Z;
    }
    else
    {
        std::cout << "No elements with such numbers.";
        exit(1);
    }
}
