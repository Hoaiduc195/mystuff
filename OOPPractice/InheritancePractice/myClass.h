#ifndef _MYCLASS
#define _MYCLASS


#include <iostream>

using namespace std;


class Human{
    private:
    string name;
    public:

    Human();
    Human(const string& n);
    ~Human();

    string getName();
    void setName(const string& n);
    void hello();
    void becomeTyrant();

    virtual void mua_quat();
};


class Student : public Human{
    friend class Teacher;
    private: 
    bool good;

    public:

    Student();
    Student(const string& a, const bool& ig);
    ~Student();
    bool isGood();
    void setStatus(const int n);
    void mua_quat() override;
};


class Teacher: public Human{
    private:
    unsigned int income;

    public:
    Teacher() {};
    Teacher(const string& n, unsigned int i);
    
    void getStudentStatus(Student& other);
    void killStudent(Student& other);
    void mua_quat() override;

};

#endif