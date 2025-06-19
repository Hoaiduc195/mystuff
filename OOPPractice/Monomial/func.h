#ifndef _MYFUNC
#define _MYFUNC

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

class Monomial{
    private:
        double heSo;
        double soMu;
    public:
    //Constructor
    Monomial(double a, double b): heSo(a), soMu(b) {};
    Monomial(): heSo(0), soMu(0) {};

    //Methods
    double getHeSo();
    double getSoMu();
    void setHeSo(double x);
    void setSoMu(double x);

    void output();
    double calc(double x);
    double diff(double x);
    double integral(double a,double b);

};

#endif