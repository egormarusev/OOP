#include "utils.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdio>
#include <QRandomGenerator>
#include <QFile>

std::string utils::qStringStdString(QString string)
{
    std::string str = string.toStdString();
    str. c_str();
    return str;
}

QString utils::StdStringtoQString(std::string string)
{
    return QString::fromStdString(string);
}

void utils::StrToMassive(const std::string s, std::vector<double>* massive)
{
    auto start = 0U;
    std::string delim = " ";
    auto end = s.find(delim);
    //int n = 0;
    while (end != std::string::npos)
    {
        massive->push_back(stoi(s.substr(start, end - start)));
        //massive[n].pushBack(stoi(s.substr(start, end - start)));
        start = end + delim.length();
        end = s.find(delim, start);
        //n++;
    }
}
std::vector<std::string> utils::parseStr(std::ifstream& file)
{
    std::vector<std::string> data;
    std::string buffer;
    std::string name;
    std::string lastName;
    std::string profit;
    std::string moneyBox;
    std::string number;
    int count = 0;
    while (!file.eof())
    {
        count++;
        getline(file, buffer);
        if (count == 1)
            name = buffer;
        if (count == 2)
            lastName = buffer;
        if (count == 3)
            profit = buffer;
        if (count == 4)
            moneyBox = buffer;
        if (count == 5)
            number = buffer;
    }

    data.push_back(name);
    data.push_back(lastName);
    data.push_back(profit);
    data.push_back(moneyBox);
    data.push_back(number);

    return data;
}

void utils::createUserFile()
{
    std::ifstream File ( "UserData.txt" );
    if(!File)
    {
        File.close();
        std::ofstream File ( "UserData.txt" );
        File << "YourName"<<"\n";
        File << "YourLastName"<<"\n";
        File << "0"<<"\n";
        File << "0"<<"\n";
        File << "1"<<"\n";
        File.close();
    }
}

std::vector<std::vector<double>> utils::parseData(std::ifstream& file)

{
    std::string buffer;
    int count = 0;

    std::vector<double> paper1;
    std::vector<double> paper2;
    std::vector<double> paper3;
    std::vector<double> paper4;
    std::vector<double> paper5;
    std::vector<double> paper6;

    std::vector<std::vector<double>> data;

    while (!file.eof() && count < 600)
    {
        count++;
        getline(file, buffer);
        std::vector<double> paper;
        utils::StrToMassive(buffer, &paper);
        for(int i = 0;i < 6; i++)
        {
            if(i == 0)
                paper1.push_back(paper.at(i));
            if(i == 1)
                paper2.push_back(paper.at(i));
            if(i == 2)
                paper3.push_back(paper.at(i));
            if(i == 3)
                paper4.push_back(paper.at(i));
            if(i == 4)
                paper5.push_back(paper.at(i));
            if(i == 5)
                paper6.push_back(paper.at(i));
        }
    }

    data.push_back(paper1);
    data.push_back(paper2);
    data.push_back(paper3);
    data.push_back(paper4);
    data.push_back(paper5);
    data.push_back(paper6);

    return data;
}

int utils::whatTimeIndex()
{

    char bufferHours[80];
    char bufferMinutes[80];
    time_t seconds = time(NULL);
    tm* timeinfo = localtime(&seconds);
    const char* formatHours = "%H";
    const char* formatMinutes = "%M";

    strftime(bufferHours, 80, formatHours, timeinfo);
    strftime(bufferMinutes, 80, formatMinutes, timeinfo);

    char a = bufferHours[0];
    char b = bufferHours[1];
    int hour = (a - '0')*10 + b - '0';

    char c = bufferMinutes[0];
    char d = bufferMinutes[1];
    int minute = (c - '0')*10 + d - '0';

    int timeStartHours = 9;
    int timeEndHours = 19;
    int time1 = 0;

    if( hour >= timeStartHours && hour < timeEndHours)
    {
        time1 = (hour - timeStartHours)*60 + minute;
        return time1;
    }
    else
    {
        return -1;
    }
}

void utils::newPrice()
{
    int m = 0;
    std::vector<double> a;

    for (int j = 0; j < 6; ++j)
        a.push_back(rand() % ((100 + 1) - 20) + 20);

    std::ifstream File("PriceList.txt");
    if (!File)
    {
        File.close();
        std::ofstream data("PriceList.txt");
        for (int i = 0; i < 600; ++i)
        {
            for (int j = 0; j < 6; ++j)
            {
                int n = a.at(j);
                m = rand() % ((5 + 1) + 5) - 5;

                while (n + m <= 0)
                {
                    m = rand() % ((5 + 1) + 5) - 5;
                }

                n = n + m;
                a.at(j) = n;

                data << n << " ";
            }
            data << "\n";
        }
        data.close();
    }
}

 void utils::addUserDataToFile(QString name, QString lastName, double profit, double moneyBox, int numberPapers)
 {
     std::ofstream File ( "UserData.txt" );
     File << utils::qStringStdString(name)<<"\n";
     File << utils::qStringStdString(lastName)<<"\n";
     File << profit<<"\n";
     File << moneyBox<<"\n";
     File << numberPapers<<"\n";
     File.close();
 }

void utils::createInvestmentFile()
 {
    std::ifstream File ( "Investments.txt" );
    if(!File)
    {
        File.close();
        std::ofstream File ( "Investments.txt" );
        File << "0"<<" "<<"0"<<" "<<"0"<<" "<<"none"<<" ";
        File.close();
    }
 }

void utils::addInvestmentFile(BoughtCollection* investments)
{
    int n = investments->getCount();
    double sum = 0;
    double num = 0;
    double price = 0;
    std::string name;
    QString line;
    QString gap = " ";

//    std::ofstream ofs;
//    ofs.open("Investments.txt", std::ofstream::out | std::ofstream::trunc);
//    ofs.close();
//    if( remove( "file.txt" ) != 0 )             // удаление файла file.txt
//         std::cout << "fuck";
//     else
//         std::cout << "nice cock";

    QFile file ("Investments.txt");
       file.remove();


    std::ofstream File ( "Investments.txt" );
    for(int i = 0;i < n; i++)
    {
        sum = investments->getInvestment(i).getSum();
        num = investments->getInvestment(i).getNumberPapers();
        price = investments->getInvestment(i).getPrice();
        name = utils::qStringStdString(investments->getInvestment(i).getPaperName());

        line = QString::number(sum) + gap +  QString::number(num)+ gap +QString::number(price)+ gap + QString::fromStdString(name);
        if(i < n - 1)
            File << utils::qStringStdString(line) <<" \n";
        else
            File << utils::qStringStdString(line) <<" ";
    }
    File.close();
}

QVector<QStringList> utils::getInvestmentsFromFile()
{
    std::ifstream file ( "Investments.txt" );
    QVector<QStringList> data;
    QStringList list;
    std::string buffer;
    QString line;
    int count = 0;
    while (!file.eof())
    {
        count++;
        getline(file, buffer);
        line = QString::fromStdString(buffer);
        list = line.split(" ");
        data.push_back(list);
    }
    file.close();
    return data;
}

std::vector<std::string> utils::getDataFromUserFile()
{
    std::ifstream file;
    file.open("UserData.txt");
    std::vector<std::string> data = utils::parseStr(file);
    file.close();
    return data;
}

bool utils::isEmpty(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}

