#include "Date.h"

Date::Date()
{
    day = 1;
    month = 1;
    year = 2000;
}

Date::~Date() {}

Date::Date(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
    if(!this->isValidDate())
    {
        day = month = 1;
        year = 2000;
    }
}

int Date::getDay()
{
    return day;
}

int Date::getMonth()
{
    return month;
}

int Date::getYear()
{
    return year;
}

bool Date::isLeapYear()
{
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

bool Date::isValidDate()
{
    if (day <= 0 || month <= 0 || year <= 0 || month > 12)
        return false;
    int daysInMonths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (!this->isLeapYear())
    {
        if (day > daysInMonths[month])
            return false;
    }
    else if (this->isLeapYear())
    {
        if (month != 2)
        {
            if (day > daysInMonths[month])
                return false;
        }
        else if (day > 29)
            return false;
    }
    return true;
}

void Date::getCurrentDate()
{
    auto now = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(now);
    tm *localTime = localtime(&currentTime);

    day = (int)localTime->tm_mday;
    month = (int)localTime->tm_mon + 1;
    year = (int)localTime->tm_year + 1900;
}

void Date::setDate(const Date &other)
{
    *this = other;
}

int Date::compareDate(const Date &other)
{
    if (year != other.year) return year - other.year;
    if (month != other.month) return month - other.month;
    return day - other.day;
}
