#include "fraction.h"

int gcd(int a, int b)
{
    a = abs(a);
    b = abs(b);
    while (a != b)
    {
        if (a < b)
            b -= a;
        else
            a -= b;
    }
    return a;
}

void Fraction::setDeno(int a)
{
    this->_deno = a;
}

void Fraction::setNum(int a)
{
    this->_num = a;
}

int Fraction::getDeno()
{
    return this->_deno;
}

int Fraction::getNum()
{
    return this->_num;
}

Fraction Fraction::inputFraction()
{
    Fraction tmp;
    int iDeno, iNum;
    cout << "Mau: ";
    cin >> iDeno;
    cout << "Tu: ";
    cin >> iNum;
    tmp.setDeno(iDeno);
    tmp.setNum(iNum);
    return tmp;
}

Fraction Fraction::inputFraction(int a, int b)
{
    if (!b)
    {
        this->setDeno(1);
        this->setNum(1);
    }
    else
    {
        this->setDeno(b);
        this->setNum(a);
    }
    return *this;
}

void Fraction::flip()
{
    int tmp = this->getDeno();
    this->setDeno(this->getNum());
    this->setNum(tmp);
}

void Fraction::modify()
{
    int tmp = gcd(this->getDeno(), this->getNum());

    this->setDeno(this->getDeno() / tmp);
    this->setNum(this->getNum() / tmp);
}

Fraction Fraction::addWithFraction(Fraction a)
{
    Fraction tmp;
    tmp.setNum(this->getNum() * a.getDeno() + this->getDeno() * a.getNum());
    tmp.setDeno(this->getDeno() * a.getDeno());
    tmp.modify();
    return tmp;
}

Fraction Fraction::subtractWithFraction(Fraction a)
{
    Fraction tmp;
    tmp.setNum(this->getNum() * a.getDeno() - this->getDeno() * a.getNum());
    tmp.setDeno(this->getDeno() * a.getDeno());
    tmp.modify();
    return tmp;
}

Fraction Fraction::multiplyWithFraction(Fraction a)
{
    Fraction tmp;
    tmp.setNum(this->getNum() * a.getNum());
    tmp.setDeno(this->getDeno() * a.getDeno());
    tmp.modify();
    return tmp;
}

Fraction Fraction::divideWithFraction(Fraction a)
{
    a.flip();
    Fraction tmp(a);
    tmp.multiplyWithFraction(a);
    tmp.modify();
    return tmp;
}

void Fraction::display()
{
    cout << this->getNum() << " / " << this->getDeno() << endl;
}
