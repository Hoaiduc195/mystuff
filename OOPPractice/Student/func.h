#ifndef FUNCTION
#define FUNCTION

#include <iostream>
#include <cstring>
using namespace std;

class Student
{
private:
    char name[1001];
    double diemVan, diemToan;

public:
    // Constructor
    Student(char n[], double a, double b)
    {
        strcpy(this->name, n);
        diemToan = a;
        diemVan = b;
    };
    Student() : name(""), diemToan(0), diemVan(0) {};

    void output();
    void input();
    char *getName();
    double getDiemVan();
    double getDiemToan();
    void setDiemVan(double x);
    void setDiemToan(double x);
    void setName(char a[]);
    double dtb();
    char *xepLoai();
};

#endif