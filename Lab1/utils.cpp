#include "utils.h"
#include "resistor.h"
#include "inductancecapacitance.h"
#include "collection.h"
#include <iostream>
#include <fstream>
#include <malloc.h>
#include <string>
#include <sstream>
#include <QtMath>

void utils::parseStr(const std::string s, double*  massive)
{
    auto start = 0U;
    std::string delim = " ";
    auto end = s.find(delim);
    int n = 0;
    while (end != std::string::npos)
    {
        massive[n] = stoi(s.substr(start, end - start));
        start = end + delim.length();
        end = s.find(delim, start);
        n++;
    }
    //massive[n] = stoi(s.substr(start, end));
}

void utils::parseStr(const std::string s, int* massive)
{
    auto start = 0U;
    std::string delim = " ";
    auto end = s.find(delim);
    int n = 0;
    while (end != std::string::npos)
    {
        massive[n] = stoi(s.substr(start, end - start));
        start = end + delim.length();
        end = s.find(delim, start);
        n++;
    }
    //massive[n] = stoi(s.substr(start, end));
}

Element*** utils::RLCtoCollection(double* resistanceM,double* lcM, int p)
{
    Element*** elements = new Element ** [2];
    for (int i = 0; i < 2; i++)
    {
        elements[i] = new Element*[p];
        for (int j = 0; j < p; j++)
            if (i == 0)
            {
                Resistor* r = new Resistor(resistanceM[j], j);
                elements[i][j] = r;
            }
            else
            {
                InductanceCapacitance* lc = new InductanceCapacitance(lcM[j], j);
                elements[i][j] = lc;
            }
    }
    return elements;
}

double** utils::convertConnectionM(double* connectionM, int p, int q)
{
    int n = 0;
    double** connection = new double* [q-1];
    for (int i = 0; i < q - 1; i++)
    {
        connection[i] = new double[p];
        for (int j = 0; j < p; j++)
        {
            connection[i][j] = connectionM[n];
            n++;
        }
    }
    return connection;
}

double** utils::multM(double** A,int rowA,int colA, double** B,int rowB, int colB)
{
    double d(1e-7);
    if (colA == rowB)
    {
        double** C = new double* [rowA];
        for (int i = 0; i < rowA; i++)
        {
            C[i] = new double[colB];
            for (int j = 0; j < colB; j++)
            {
                C[i][j] = 0;
                for (int k = 0; k < colA; k++)
                    C[i][j] += A[i][k] * B[k][j];

            }
        }
        for (int i = 0; i < rowA; i++)
        {
            for (int k = 0; k < colB; k++)
            {
                if ((C[i][k] < d && C[i][k] > 0) || (C[i][k] > (-1) * d && C[i][k] < 0))
                    C[i][k] = 0;
            }
        }
        return C;
    }
    else
    {
        std::cout << "Matrices have wrong demension" << "\n";
        exit(1);
    }
}

double** utils::sumM(double** A, int rowA, int colA, double** B, int rowB, int colB)
{
    if (rowA == rowB && colA == colB)
    {
        double** C = new double* [rowA];
        for (int i = 0; i < rowA; i++)
        {
            C[i] = new double[colB];
            for (int j = 0; j < colB; j++)
                C[i][j] = A[i][j] + B[i][j];
        }
        return C;
    }
    else
    {
        std::cout << "Matrices have wrong demension" << "\n";
         exit(1);
    }
}

double** utils::transpose(double** A, int rowA, int colA)
{
    double** B = new double* [colA];
    for (int i = 0; i < colA; i++)
        B[i] = new double[rowA];

    for (int i = 0; i < rowA; i++)
    {
        for (int j = 0; j < colA; j++)
            B[j][i] = A[i][j];
    }
    return B;
}

double** utils::transposeMasive(double* A, int n)
{
    double** B = new double* [n];
    for (int i = 0; i < n; i++)
        B[i] = new double[1];

    for (int i = 0; i < n;i++)
        B[i][0] = A[i];
    return B;
}

/*
double utils::det(double** A, int rowA, int colA)
{
    if (rowA == colA)
    {
        if (rowA == 1)
            return A[0][0];
        else if (rowA == 2)
            return A[0][0] * A[1][1] - A[0][1] * A[1][0];
        else {
            double d = 0;
            for (int k = 0; k < rowA; k++) {
                double** b = DBG_NEW double* [rowA - 1];
                for (int i = 0; i < rowA - 1; i++) {
                    b[i] = DBG_NEW double[rowA - 1];
                }
                for (int i = 1; i < rowA; i++) {
                    for (int j = 0; j < rowA; j++) {
                        if (j == k)
                            continue;
                        else if (j < k)
                            b[i - 1][j] = A[i][j];
                        else
                            b[i - 1][j - 1] = A[i][j];
                    }
                }
                d += pow(-1, k + 2) * A[0][k] * utils::det(b, rowA - 1, rowA - 1);

                utils::cleanMemory(b, rowA - 1);
            }
            return d;
        }
    }
    else
    {
        std::cout << "Matrix has wrong demension";
        exit(1);
    }
}
*/


double** utils::inversion(double** B, int N)
{
    double** A = utils::clone(B, N, N);
    double temp;
    double** E = new double* [N];

    for (int i = 0; i < N; i++)
        E[i] = new double[N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            E[i][j] = 0.0;

            if (i == j)
                E[i][j] = 1.0;
        }

    for (int k = 0; k < N; k++)
    {
        temp = A[k][k];

        for (int j = 0; j < N; j++)
        {
            A[k][j] /= temp;
            E[k][j] /= temp;
        }

        for (int i = k + 1; i < N; i++)
        {
            temp = A[i][k];

            for (int j = 0; j < N; j++)
            {
                A[i][j] -= A[k][j] * temp;
                E[i][j] -= E[k][j] * temp;
            }
        }
    }

    for (int k = N - 1; k > 0; k--)
    {
        for (int i = k - 1; i >= 0; i--)
        {
            temp = A[i][k];

            for (int j = 0; j < N; j++)
            {
                A[i][j] -= A[k][j] * temp;
                E[i][j] -= E[k][j] * temp;
            }
        }
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            A[i][j] = E[i][j];

    for (int i = 0; i < N; i++)
        delete[] E[i];
     delete[] E;

     return A;
}



    double** utils::clone(double** A, int rowA, int colA)
    {
       double** clone = new double* [rowA];
        for (int row = 0; row < rowA; row++)
        {
            clone[row] = new double[colA];
            for (int col = 0; col < colA; col++)
                clone[row][col] = A[row][col];
        }
        return clone;
    }

    void utils::cleanMemory(double** A, int n)
    {
        for (int i = 0; i < n; i++)
            delete[] A[i];
        delete[] A;
    }

    void utils::cleanMemory(Element*** A, int n, int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                delete A[i][j];
            }
            delete[] A[i];
        }
        delete[] A;
    }

    double** utils::CollectionToY(Element*** collection, int p)
    {
        double** Y;
        Y = new double *[p];
        for (int k = 0; k < p; k++)
            Y[k] = new double[p];

        for (int i = 0; i < p; i++)
            for (int j = 0; j < p; j++)
            {
                if (i == j)
                {
                    if (collection[0][j]->getElementResistance() != 0)
                        Y[i][j] = 1.0 / collection[0][j]->getElementResistance();
                    else
                        Y[i][j] = 0;
                }
                else
                {
                    Y[i][j] = 0;
                }
            }
        return Y;
    }

    double** utils::multScalar(double** A, int rowA, int colA, int d)
    {
        double** B = new double* [rowA];
            for (int i = 0; i < rowA; i++)
            {
                B[i] = new double[colA];
                for (int j = 0; j < colA; j++)
                {
                    B[i][j] = A[i][j] * d;
                }
            }
        return B;
    }

    double* utils::makeMassiveU0(double** A, int n)
    {
        double* B = new double[n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 1; j++)
            {
                B[i] = A[i][j];
            }
        return B;
    }

    void utils::printM(double** &A, int n, int m)
    {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                std::cout << A[i][j] << " ";
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    int* utils::findPQ(std::ifstream& file)
    {
        std::string  stringPQ;
        std::string  buffer;
        int count = 0;
        while (!file.eof())
        {
            count++;
            getline(file, buffer);
            if (count == 1)
               stringPQ = buffer;
        }

        int* pqM = new int[2];
        //pqM[0] = 0;
        utils::parseStr(stringPQ, pqM); // Получение полей для записи из файла
        return pqM;

    }
