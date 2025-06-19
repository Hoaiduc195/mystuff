#ifndef _CLASS_H_
#define _CLASS_H_

#include <vector>
#include <iomanip>
#include <algorithm>
#include "Teacher.h"
#include "Student.h"

using namespace std;

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

    // Student* getStudentIndex(int idx); // bug
    //File Manipulation

    bool saveToFile(string& filename); //Binary File
    bool readFile(string& filename);
};

#endif