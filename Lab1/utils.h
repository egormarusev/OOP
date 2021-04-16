#ifndef UTILS_H
#define UTILS_H


#include <string>
#include "element.h"
class utils
{
public:
    static void parseStr(const std::string s, double* massive); // Функция для записи даты из строки в массив int
    static void parseStr(const std::string s, int* massive);
    static Element*** RLCtoCollection(double* resistanceM, double* lcM, int p);
    static double** convertConnectionM(double* connectionM, int p, int q);
    static double** multM(double** A, int rowA, int colA, double** B, int rowB, int colB);
    static double** sumM(double** A, int rowA, int colA, double** B, int rowB, int colB);
    static double** transpose(double** A, int rowA, int colA);
    static double** transposeMasive(double* A, int n);
    static double** inversion(double** A, int N);
    static double** clone(double** A, int rowA, int colA);
    static void cleanMemory(double** a, int n);
    static void cleanMemory(Element*** a, int n, int m);
    static double** CollectionToY(Element*** collection, int p);
    static double** multScalar(double** A, int rowA, int colA, int d);
    static double* makeMassiveU0(double** A, int n);
    static void printM(double** &A, int n, int m);
    static int* findPQ(std::ifstream& file);
};
#endif // UTILS_H
