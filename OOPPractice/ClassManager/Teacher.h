#ifndef _TEACHER_H_
#define _TEACHER_H_

#include <iostream>
#include <regex>
using namespace std;

bool isValidPhoneNumber(const string& phoneNumber);


class Teacher{
    private:
    string name;
    string email;
    string phoneNumber;

    public:

    Teacher();
    ~Teacher();
    Teacher(const string& n, const string& e, const string& p): name(n), email(e), phoneNumber(p) {};

    //Getters, Setters
    string getName();
    string getEmail();
    string getPhoneNumber();

    void setName(const string& newName);

    // static bool isValidEmail(const string& mail);
    void setEmail(const string& newEmail);

    // static bool isValidPhoneNumber(const string &phoneNumber);
    void setPhoneNumber(const string& newPhoneNumber);
    //Methods
    
    friend ostream& operator<<(ostream& out, const Teacher& teacher){
        out<<teacher.name<<" "<<teacher.email<<" "<<teacher.phoneNumber;
        return out;
    }


    void clear();

};



#endif