#include "func.h"

double Monomial::getHeSo()
{
    return this->heSo;
}
double Monomial::getSoMu()
{
    return this->soMu;
}
void Monomial::setHeSo(double x)
{
    this->heSo = x;
}
void Monomial::setSoMu(double x)
{
    this->soMu = x;
}

void Monomial::output()
{
    cout << this->getHeSo() << "x^" << this->getSoMu() << endl;
}
double Monomial::calc(double x)
{
    double hs = this->getHeSo();
    return hs * pow(x, this->getSoMu());
}
double Monomial::diff(double x)
{
    double tiny = 1e-5;
    return (this->calc(x + tiny) - this->calc(x - tiny)) / (2.0 * tiny);
}
double Monomial::integral(double a, double b)
{
    double sum = 0;
    int n = 10e5;
    double delta = (b - a) / (n * 1.0);
    double hs = this->getHeSo();
    for (int i = 0; i <= n; i++)
    {
        sum += hs * pow(a + (i - 0.5) * delta, this->getSoMu()) * delta;
    }
    return sum;
}
