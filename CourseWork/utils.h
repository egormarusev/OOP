#ifndef UTILS_H
#define UTILS_H

#include <QString>
#include <vector>
#include "PaperCollection.h"
#include "BoughtCollection.h"


class utils
{
public:
    static std::string qStringStdString(QString string);
    static QString StdStringtoQString(std::string string);
    static void StrToMassive(const std::string s, std::vector <double>*massive);
    static std::vector<std::string> parseStr(std::ifstream& file);
    static std::vector<std::vector<double>> parseData(std::ifstream& file);
    static void createUserFile();
    static std::vector<std::string> getDataFromUserFile();
    static int whatTimeIndex();
    static void newPrice();
    static void addUserDataToFile(QString name, QString lastName, double profit, double moneyBox, int numberPapers);
    static void createInvestmentFile();
    static void addInvestmentFile(BoughtCollection* investments);
    static QVector<QStringList> getInvestmentsFromFile();
    static bool isEmpty(std::ifstream& pFile);
};

#endif // UTILS_H
