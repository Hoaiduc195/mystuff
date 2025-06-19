#ifndef _STUDENT_H_
#define _STUDENT_H_


#include <iostream>
#include <fstream>
#include "Date.h"
using namespace std;


struct Transcript{
    double MathematicPoint;
    double PhysicsPoint;
    double ChemistryPoint;
    double EnglishPoint;

    Transcript(): MathematicPoint(0.0), PhysicsPoint(0.0), ChemistryPoint(0.0), EnglishPoint(0.0) {};
    Transcript(double m, double p, double c, double e): MathematicPoint(m), PhysicsPoint(p), ChemistryPoint(c), EnglishPoint(e) {};
};

class Student{
    private:
    string name;
    string email;
    Transcript transcript;
    Date birthday;
    

    public:
    Student();
    ~Student();
    Student(const string& n, const string& e, Transcript& t, Date bd): name(n), email(e), transcript(t), birthday(bd) {};

    //Getters, Setters
    string getName();
    string getEmail();
    Transcript getTranscript();
    string getStringTranScript();
    Date getBirthday();
    void saveTranscript(const string& fileName);

    void setName(const string& newName);
    void setEmail(const string& newEmail);
    void adjustTranscript();
    void setTranscript(const Transcript& t);
    void setBirthday(const Date& other);
    double getGPA();

    //Methods

};

#endif