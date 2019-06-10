#ifndef WORKER_H_INCLUDED
#define WORKER_H_INCLUDED

#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <utility>
#include <algorithm>

struct data
{
    int         id;
    std::string surname;
    std::string name;
    std::string patronymic;
    std::string post;
    double      hrPay;
    int         hours;
};

class Worker
{
private:
    data m_data;
    std::vector<data> m_personal;
    char m_choice;
    static char m_sort_choice;

    void printHeader();
    void printLine(const data&);


public:
    Worker();

    void menu();

    void newWorker();

    template <typename T>
    void setNumber(std::string, T&);
    std::string getString(const std::string&);

    void editData();

    void findWorker();

    void deleteData();

    void showAll();

    void saveToFile();

    void loadFromFile();

    void sortData();

    void sortBubble();

    void sortShell();

    static bool comp (const data& , const data& );

    void quit();

};

#endif // WORKER_H_INCLUDED
