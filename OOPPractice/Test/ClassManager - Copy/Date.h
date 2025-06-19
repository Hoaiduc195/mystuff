#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

class Date{
    public:
    int day, month, year;

    Date();
    ~Date();
    Date(int d, int m, int y);

    // Date(const Date& w){
    //     *this = w;
    // } 
    int getDay();
    int getMonth();
    int getYear();

    bool isLeapYear();
    bool isValidDate();
    void getCurrentDate();
    void setDate(const Date& other);
    int compareDate(const Date& other);

    friend ostream& operator<<(ostream& out, const Date& date){
        out<<date.day<<"/"<<date.month<<"/"<<date.year;
        return out;
    }

};


#endif