#include "myClass.h"



//Constructors / Destructors of Human class
Human::Human(){
    this->name = "<unknown>";
    cout<<"Initialize successfully a human."<<endl;
}

Human::Human(const string& n){
    this->name = n;
    cout<<"Initialize successfully a human named "<<n<<"."<<endl;
}

Human::~Human(){
    cout<<"Eliminate successfully a human named "<<this->name<<"."<<endl;
}

//Human's methods
string Human::getName(){
    return this->name;
}

void Human::setName(const string& n){
    this->name = n;
}

void Human::hello(){
    cout<<"Xin chao.";
}

void Human::becomeTyrant(){
    cout<<this->name<<" has become a tyrant."<<endl;
}

void Human::mua_quat(){
    cout<<"Con nguoi dang mua quat."<<endl;
}

//Constructors and Destructors of Student class
Student::Student(){
    cout<<"A Human named "<<this->getName()<<" has become a student."<<endl;
}

Student::Student(const string& a,const bool& ig){
    this->setName(a);
    this->good = ig;
    cout<<"A human named "<<a<<" has become a student and this guy is "<<(ig? "good":"not good")<<" at learning new things."<<endl;
}   

Student::~Student(){
    cout<<"Student named "<<this->getName()<<" has dropped out."<<endl;
}

//Student's methods
bool Student::isGood(){
    return this->good;
}
void Student::setStatus(const int n){
    this->good = n;
}

void Student::mua_quat(){
    cout<<"Hoc sinh "<<this->getName()<<" dang mua quat hang say."<<endl;
}


//Constructors and Destructors of Teachers
Teacher::Teacher(const string& n, unsigned int i){
    cout<<"A human named "<<n<<" has become a teacher and has income: "<<i<<"."<<endl;
    this->setName(n);
    this->income = i;
}

void Teacher::getStudentStatus(Student& other){
    if(other.isGood()) cout<<this->getName()<<" find out "<<other.getName()<<" is "<<(other.good?"good.":"not good.")<<endl;
}

void Teacher::killStudent(Student& other){
    cout<<"Teacher named "<<this->getName()<<" has killed student "<<other.getName()<<". Therfore, ";
    other.~Student();
}

void Teacher::mua_quat() {
    cout<<"Giao vien "<<this->getName()<<" dang mua quat."<<endl;
}



