#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
using namespace std;

class Fraction
{

private:
    int _num;
    int _deno;

public:
    // Constructor
    Fraction() : _num(1), _deno(1) {};
    Fraction(int a, int b) : _num(a), _deno(b) {};
    Fraction operator+(Fraction other){
        return this->addWithFraction(other);
    }
    Fraction operator-(Fraction other){
        return this->subtractWithFraction(other);
    }
    Fraction operator*(Fraction other){
        return this->multiplyWithFraction(other);
    }
    Fraction operator/(Fraction other){
        return this->divideWithFraction(other);
    }
    // Method
    Fraction inputFraction();
    Fraction inputFraction(int a, int b);
    int getNum();
    int getDeno();
    void setNum(int a);
    void setDeno(int a);
    void flip();
    void modify();
    Fraction addWithFraction(Fraction a);
    Fraction subtractWithFraction(Fraction a);
    Fraction multiplyWithFraction(Fraction a);
    Fraction divideWithFraction(Fraction a);
    void display();
};

#endif