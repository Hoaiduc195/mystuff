#ifndef _BOOKMAG
#define _BOOKMAG

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Author{
    private:
    string name;
    string email;
    public:
    Author();
    ~Author();
    Author(const string& n, const string& e): name(n), email(e) {};

    void setName(const string& newName);
    string getName();
    void setEmail(const string& newEmail);
    string getEmail();
};


class Book{
    private:
    string name;
    vector<Author> authors;
    double price;
    
    public:
    Book();
    ~Book();
    Book(const string& n, vector<Author> a, double p): name(n), authors(a), price(p) {};
    
    void setName(const string& newName);
    string getName();
    void setPrice(const double& newPrice);
    double getPrice();
    string getAuthorNames();
};




#endif