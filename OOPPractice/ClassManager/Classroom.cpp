#include "Classroom.h"

Classroom::Classroom()
{
}

Classroom::~Classroom()
{
}

// Getters/ Setters
void Classroom::setHeadMaster(const Teacher &newHeadMaster)
{
    headMaster = newHeadMaster;
}

void Classroom::setStudents(const vector<Student> &newStudentsList)
{
    students = newStudentsList;
}

Teacher Classroom::getHeadMaster()
{
    return headMaster;
}

vector<Student> Classroom::getStudents()
{
    return students;
}

int Classroom::getClassSize()
{
    return (int)students.size();
}

Student Classroom::getOneGuy(int idx)
{
    if(idx<0||idx>=(int)students.size()){
        return Student();
    }

    return students[(size_t)idx];
}

string Classroom::getFileName()
{
    return filename;
}

void Classroom::setFileName(const string &newFilename)
{
    filename = newFilename;
}

// Methods

void printline()
{
    for (int i = 0; i < 100; i++)
    {
        cout << "-";
    }
    cout << endl;
}

void Classroom::displayStudents()
{
    printline();
    for (size_t i = 0; i < students.size(); i++)
    {
        cout << setw(25) << students[i].getName() << setw(5) << students[i].getEmail() << setw(12) << students[i].getBirthday();
    }
    printline();
}

void Classroom::displayClass()
{
    cout << "Head Master: ";
    cout << headMaster << endl;
    displayStudents();
}

// Sorting Methods-----------------------------------------------------
int compareNameString(string a, string b)
{
    string firstNameA, firstNameB;
    string tmp;

    stringstream A(a), B(b);
    while (A >> tmp)
    {
        firstNameA = tmp;
    }

    while (B >> tmp)
    {
        firstNameB = tmp;
    }

    for (size_t i = 0; i < min(firstNameA.length(), firstNameB.length()); i++)
    {
        if (firstNameA[i] != firstNameB[i])
            return firstNameA[i] - firstNameB[i];
    }

    return (int)(firstNameA.length() - firstNameB.length());
}

bool nameComparator(Student A, Student B)
{
    // Sorting Increasing Lexicographically
    if (compareNameString(A.getName(), B.getName()) > 0)
        return false;
    return true;
}

void Classroom::sortByName()
{
    sort(begin(students), end(students), nameComparator);
}

bool birthdayComparator(Student A, Student B)
{
    // Sorting Increasingly Date
    if (A.getBirthday().compareDate(B.getBirthday()) > 0)
        return false;
    return true;
}

void Classroom::sortByBirthday()
{
    sort(begin(students), end(students), birthdayComparator);
}

bool GPAComparator(Student A, Student B)
{
    return A.getGPA() > B.getGPA();
}

void Classroom::sortByGPA()
{
    sort(begin(students), end(students), GPAComparator);
}

void Classroom::addStudent(const Student &newStudent)
{
    students.push_back(newStudent);
    sortByName();
}

void Classroom::removeStudent(const int& idx)
{
    // size_t idx;
    // bool found = false;
    // for (size_t i = 0; i < students.size(); i++)
    // {
    //     if (students[i].getName() == removeStudentName)
    //     {
    //         idx = i;
    //         found = true;
    //     }
    // }
    // if (!found)
    // {
    //     cout << "No student with name " << removeStudentName << " to remove." << endl;
    // }
    // else
    //     students.erase(students.begin() + (int)idx);

    if(idx<0 || idx>=(int)students.size()){
        cout<<"No student available to remove."<<endl;
        return;
    }else students.erase(students.begin()+idx);
}

void Classroom::clear()
{
    headMaster.clear();
    students.clear();
    filename = "";
}

void Classroom::swapGuyWith(int idx, const Student &newGuy)
{
    if(idx<0 || idx>=(int)students.size()) return;
    
    students[(size_t)idx] = newGuy;
}

bool Classroom::saveToFile(string &Filename)
{
    string prefix = "ClassroomFile\\";
    prefix += Filename;
    Filename = prefix;
    fstream output(Filename, ios::binary);
    if (!output.is_open())
    {
        return false;
    }
    output.write((char *)this, sizeof(Classroom));
    output.close();

    return true;
}



bool Classroom::readFile(string &Filename)
{
    string prefix = "ClassroomFile\\";
    prefix+= Filename;
    Filename = prefix;
    fstream input(Filename, ios::binary);
    if (!input.is_open())
    {
        return false;
    }

    input.read((char *)this, sizeof(Classroom));
    input.close();
    return true;
}
