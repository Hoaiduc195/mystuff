#include "Teacher.h"

bool isValidPhoneNumber(const string &phoneNumber)
{
    for (char x : phoneNumber)
    {
        if (x < '0' || x > '9')
            return false;
    }

    return true;
}

Teacher::Teacher()
{
    return;
}

Teacher::~Teacher()
{
    return;
}

string Teacher::getName()
{
    return name;
}

string Teacher::getEmail()
{
    return email;
}

string Teacher::getPhoneNumber()
{
    return phoneNumber;
}

void Teacher::setName(const string &newName)
{
    name = newName;
}



void Teacher::setEmail(const string &newEmail)
{
    email = newEmail;
}

void Teacher::setPhoneNumber(const string &newPhoneNumber)
{
    if (isValidPhoneNumber(newPhoneNumber))
        phoneNumber = newPhoneNumber;
    else
        cout << "Invalid phone number." << endl;
}

void Teacher::clear()
{
    name = email = phoneNumber = "";
}
