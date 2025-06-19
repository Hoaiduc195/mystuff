#include "func.h"

char *Student::getName()
{
    return this->name;
}

double Student::getDiemVan()
{
    return this->diemVan;
}

double Student::getDiemToan()
{
    return this->diemToan;
}

void Student::setDiemVan(double x)
{
    this->diemVan = x;
}

void Student::setDiemToan(double x)
{
    this->diemToan = x;
}

void Student::setName(char a[])
{
    strcpy(this->name, a);
}

void Student::input()
{
    double a, b;
    cout << "Nhap ten: ";
    char buffer[1001];
    cin.getline(buffer,1001);
    this->setName(buffer);
    cout << "Nhap diem toan va diem van: ";
    cin >> a >> b;

    this->setDiemToan(a);
    this->setDiemVan(b);
}

double Student::dtb()
{
    return this->diemToan / 2.0 + this->diemVan / 2.0;
}

char *Student::xepLoai(){
    if(this->dtb()>=8.0){
        return "Gioi";
    }
    if(this->dtb()>=7.0){
        return "Kha";
    }
    if(this->dtb()>=5.0){
        return "Trung Binh";
    }
    if(this->dtb()<5.0) return "Yeu";
}

void Student::output(){
    cout<<this->name<<":"<<endl;
    cout<<"Diem toan: "<<this->diemToan<<endl;
    cout<<"Diem van: "<<this->diemVan<<endl;
    cout<<"DTB: "<<this->dtb()<<endl;
    cout<<"Xep Loai: "<<this->xepLoai()<<endl;
}