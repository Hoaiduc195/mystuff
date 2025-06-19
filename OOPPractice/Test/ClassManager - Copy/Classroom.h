#ifndef _CLASS_H_
#define _CLASS_H_

#include <vector>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <regex>
#include "Date.h"

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

/*__________________________________________________________________________________________________________*/
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
/*_______________________________________________________________________________________________________*/

class Classroom{
    private:
    Teacher headMaster;
    vector<Student> students;
    string filename;
    public: 

    Classroom();
    ~Classroom();
    Classroom(Teacher head, vector<Student>& s): headMaster(head), students(s) {};

    //Getters/ Setters
    void setHeadMaster(const Teacher& newHeadMaster);
    void setStudents(const vector<Student>& newStudentsList);
    // Teacher* getHeadMaster(); //bug
    Teacher getHeadMaster();
    vector<Student> getStudents();
    int getClassSize();
    Student getOneGuy(int idx);
    string getFileName();
    void setFileName(const string& newFilename);

    //Methods
    void displayStudents();
    void displayClass(); // including headMaster
    void sortByName();
    void sortByBirthday();
    void sortByGPA();
    void addStudent(const Student& newStudent);
    void removeStudent(const int& idx);
    void clear();
    void swapGuyWith(int idx, const Student& newGuy);
    
    //File Manipulation

    bool saveToFile(string& filename); //Binary File
    bool readFile(string& filename);
};

#endif