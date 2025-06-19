#include "BookManager.h"

// Author
Author::Author()
{
    return;
}
Author::~Author()
{
    return;
}

void Author::setName(const string &newName)
{
    this->name = newName;
}
string Author::getName()
{
    return this->name;
}
void Author::setEmail(const string &newEmail)
{
    this->email = newEmail;
}
string Author::getEmail()
{
    return this->email;
}

// Book
Book::Book(){
    return;
}
Book::~Book(){
    return;
}

void Book::setName(const string &newName){
    this->name = newName;
}
string Book::getName(){
    return this->name;
}
void Book::setPrice(const double &newPrice){
    this->price = newPrice;
}
double Book::getPrice(){
    return this->price;
}
string Book::getAuthorNames(){
    string AuthorsString = "";
    vector<Author> getString = this->authors;

    for(auto x:getString){
        AuthorsString += x.getName();
        AuthorsString += " ";
    }

    AuthorsString.erase(AuthorsString.length()-1);

    return AuthorsString;

}