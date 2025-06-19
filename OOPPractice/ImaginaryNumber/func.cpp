#include "func.h"

void SoPhuc::setPhanThuc(double x)
{
    this->phanThuc = x;
}
void SoPhuc::setPhanAo(double x)
{
    this->phanAo = x;
}
double SoPhuc::getPhanAo()
{
    return this->phanAo;
}
double SoPhuc::getPhanThuc()
{
    return this->phanThuc;
}
void SoPhuc::setValue()
{
    int a, b;
    cin >> a >> b;
    this->setPhanThuc(a);
    this->setPhanAo(b);
}
void SoPhuc::setValue(double a, double b)
{
    this->setPhanThuc(a);
    this->setPhanAo(b);
}

void SoPhuc::output()
{
    cout << this->getPhanThuc() << " + " << this->getPhanAo() << "i" << endl;
}

double SoPhuc::getModule()
{
    return sqrt(pow(this->getPhanThuc(), 2.0) + pow(this->getPhanAo(), 2.0));
}

SoPhuc SoPhuc::cong(SoPhuc other)
{
    SoPhuc tmp;
    tmp.setPhanThuc(this->getPhanThuc() + other.getPhanThuc());
    tmp.setPhanAo(this->getPhanAo() + other.getPhanAo());
    return tmp;
}

SoPhuc SoPhuc::tru(SoPhuc other)
{
    SoPhuc tmp;
    double thuc = this->getPhanThuc() - other.getPhanThuc();
    double ao = this->getPhanAo() - other.getPhanAo();
    tmp.setPhanThuc(thuc);
    tmp.setPhanAo(ao);
    return tmp;
}
SoPhuc SoPhuc::nhan(SoPhuc other)
{
    SoPhuc tmp;
    tmp.setPhanThuc(this->getPhanThuc() *other.getPhanThuc()  -  this->getPhanAo()* other.getPhanAo());
    tmp.setPhanAo(this->getPhanThuc() * other.getPhanAo() + other.getPhanThuc() * this->getPhanAo());
    return tmp;
}

SoPhuc SoPhuc::chia(SoPhuc other)
{
    double tmp = pow(other.getPhanThuc(), 2.0) + pow(other.getPhanAo(), 2.0);
    double thuc = (this->getPhanThuc() * other.getPhanThuc() + this->getPhanAo() * other.getPhanAo()) / tmp;
    double ao = (this->getPhanAo() * other.getPhanThuc() - this->getPhanThuc() * other.getPhanAo()) / tmp;
    SoPhuc ans;
    ans.setPhanThuc(thuc);
    ans.setPhanAo(ao);

    return ans;
}
