#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

class Date{
    private:
    int day, month, year;

    public:

    Date();
    ~Date();
    Date(int d, int m, int y);

    // Date(const Date& w){
    //     *this = w;
    // } 
    
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