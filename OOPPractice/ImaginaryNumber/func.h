#ifndef _MYFUNC
#define _MYFUNC

#include <iostream>
#include <math.h>

using namespace std;

class SoPhuc
{
private:
    double phanThuc;
    double phanAo;

public:
    // Constructor
    SoPhuc(double a, double b) : phanThuc(a), phanAo(b) {};
    SoPhuc() : phanThuc(0), phanAo(0) {};
    SoPhuc(double a): phanThuc(a), phanAo(0) {};

    // Methods
    void setPhanThuc(double x);
    void setPhanAo(double x);
    double getPhanAo();
    double getPhanThuc();
    void setValue();
    void setValue(double a, double b);
    void output();
    double getModule();
    SoPhuc cong(SoPhuc other);
    SoPhuc tru(SoPhuc other);
    SoPhuc nhan(SoPhuc other);
    SoPhuc chia(SoPhuc other);
};

#endif