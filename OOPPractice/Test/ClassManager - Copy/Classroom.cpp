#include "Classroom.h"

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

/*____________________________________________________________________________________________________________*/
Student::Student() {}
Student::~Student() {}

string Student::getName()
{
    return name;
}
string Student::getEmail()
{
    return email;
}

Transcript Student::getTranscript()
{
    return transcript;
}
string Student::getStringTranScript()
{
    string transcriptString = "";
    transcriptString += "Mathematics: " + to_string(transcript.MathematicPoint) + " ";
    transcriptString += "Chemistry: " + to_string(transcript.ChemistryPoint) + " ";
    transcriptString += "English: " + to_string(transcript.EnglishPoint) + " ";
    transcriptString += "Physics: " + to_string(transcript.PhysicsPoint) + ".";
    return transcriptString;
}

Date Student::getBirthday()
{
    return birthday;
}

void Student::saveTranscript(const string &fileName)
{

    fstream output(fileName, ios::out);
    if (!output.is_open())
    {
        cout << "Can not open file name: " << fileName << endl;
        return;
    }

    string saveString = getStringTranScript();
    output << name << ": ";
    output << saveString;

    output.close();
}

void Student::setName(const string &newName)
{
    name = newName;
}
void Student::setEmail(const string &newEmail)
{
    email = newEmail;
}

void printMenuTranscriptConfig()
{
    cout << "+-------------------------------------------------+" << endl;
    cout << "|           Choose Subject To Adjust              |" << endl;
    cout << "+-------------------------------------------------+" << endl;
    cout << "|    1.Mathematics.                               |" << endl;
    cout << "|    2.Chemistry.                                 |" << endl;
    cout << "|    3.English.                                   |" << endl;
    cout << "|    4.Physics.                                   |" << endl;
    cout << "|    0.Exit                                       |" << endl;
    cout << "+-------------------------------------------------+" << endl;
}

void Student::adjustTranscript()
{
    bool exit = false;
    while (true)
    {
        if (exit)
            break;
        printMenuTranscriptConfig();
        cout << "Input: ";
        int input = 0;
        cin >> input;
        switch (input)
        {
        case 1:
        {
            double newMark;
            cout << "Current Mathematics Mark: " << transcript.MathematicPoint << endl;
            cout << "New Mathematics Mark: ";
            cin >> newMark;
            transcript.MathematicPoint = newMark;
            break;
        }
        case 2:
        {
            double newMark;
            cout << "Current Chemistry Mark: " << transcript.ChemistryPoint << endl;
            cout << "New Chemistry Mark: ";
            cin >> newMark;
            transcript.ChemistryPoint = newMark;
            break;
        }
        case 3:
        {
            double newMark;
            cout << "Current English Mark: " << transcript.EnglishPoint << endl;
            cout << "New English Mark: ";
            cin >> newMark;
            transcript.EnglishPoint = newMark;
            break;
        }
        case 4:
        {
            double newMark;
            cout << "Current Physics Mark: " << transcript.PhysicsPoint << endl;
            cout << "New Physics Mark: ";
            cin >> newMark;
            transcript.PhysicsPoint = newMark;
            break;
        }
        case 0:
        {
            exit = true;
            break;
        }
        }
    }
}

void Student::setTranscript(const Transcript &t)
{
    transcript = t;
}

void Student::setBirthday(const Date &other)
{
    birthday = other;
}

double Student::getGPA()
{
    double sum = transcript.MathematicPoint + transcript.ChemistryPoint + transcript.EnglishPoint + transcript.PhysicsPoint;
    return sum / 4.0;
}

/*_____________________________________________________________________________________________________*/

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
    if (idx < 0 || idx >= (int)students.size())
    {
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
    for (int i = 0; i < 120; i++)
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
        cout << setw(30) << students[i].getName() << setw(35) << students[i].getEmail() << setw(12) << students[i].getBirthday() <<endl;
    }
    printline();
    cout<<endl;
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

void Classroom::removeStudent(const int &idx)
{

    if (idx < 0 || idx >= (int)students.size())
    {
        cout << "No student available to remove." << endl;
        return;
    }
    else
        students.erase(students.begin() + idx);
}

void Classroom::clear()
{
    headMaster.clear();
    students.clear();
    filename = "";
}

void Classroom::swapGuyWith(int idx, const Student &newGuy)
{
    if (idx < 0 || idx >= (int)students.size())
        return;

    students[(size_t)idx] = newGuy;
}

bool Classroom::saveToFile(string &Filename)
{
    string prefix = "D:\\n_zq\\CPP\\OOPPractice\\Test\\ClassManager - Copy\\ClassroomFile\\";
    prefix += Filename;
    Filename = prefix;

    ofstream output(Filename, ios::binary | ios::trunc); // Overwrites, but safely
    if (!output.is_open())
    {
        cout << "Error: Unable to open file " << Filename << " for writing." << endl;
        return false;
    }

    // Save Teacher
    string headMasterName = headMaster.getName();
    string headMasterEmail = headMaster.getEmail();
    string headMasterPhone = headMaster.getPhoneNumber();

    size_t headMasterNameSize = headMasterName.size();
    size_t headMasterEmailSize = headMasterEmail.size();
    size_t headMasterPhoneSize = headMasterPhone.size();

    output.write(reinterpret_cast<char *>(&headMasterNameSize), sizeof(size_t));
    output.write(headMasterName.c_str(), static_cast<std::streamsize>(headMasterNameSize));

    output.write(reinterpret_cast<char *>(&headMasterEmailSize), sizeof(size_t));
    output.write(headMasterEmail.c_str(), static_cast<std::streamsize>(headMasterEmailSize));

    output.write(reinterpret_cast<char *>(&headMasterPhoneSize), sizeof(size_t));
    output.write(headMasterPhone.c_str(), static_cast<std::streamsize>(headMasterPhoneSize));

    // Save Students
    size_t studentCount = students.size();
    output.write(reinterpret_cast<char *>(&studentCount), sizeof(size_t));

    for (auto &student : students)
    {
        string studentName = student.getName();
        string studentEmail = student.getEmail();
        Date studentBirthday = student.getBirthday();
        Transcript transcript = student.getTranscript();

        size_t studentNameSize = studentName.size();
        size_t studentEmailSize = studentEmail.size();

        output.write(reinterpret_cast<char *>(&studentNameSize), sizeof(size_t));
        output.write(studentName.c_str(), static_cast<std::streamsize>(studentNameSize));

        output.write(reinterpret_cast<char *>(&studentEmailSize), sizeof(size_t));
        output.write(studentEmail.c_str(), static_cast<std::streamsize>(studentEmailSize));

        // Save birthday using getters
        int day = studentBirthday.getDay();
        int month = studentBirthday.getMonth();
        int year = studentBirthday.getYear();

        output.write(reinterpret_cast<char *>(&day), sizeof(int));
        output.write(reinterpret_cast<char *>(&month), sizeof(int));
        output.write(reinterpret_cast<char *>(&year), sizeof(int));

        // Save transcript
        output.write(reinterpret_cast<char *>(&transcript), sizeof(Transcript));
    }

    output.close();
    return true;
}

bool Classroom::readFile(string &Filename)
{
    string prefix = "D:\\n_zq\\CPP\\OOPPractice\\Test\\ClassManager - Copy\\ClassroomFile\\";
    prefix += Filename;
    Filename = prefix;
    ifstream input(Filename, ios::binary);
    if (!input.is_open())
    {
        cout << "Error: Unable to open file " << Filename << " for reading." << endl;
        return false;
    }

    // Read HeadMaster
    size_t headMasterNameSize, headMasterEmailSize, headMasterPhoneSize;
    string headMasterName, headMasterEmail, headMasterPhone;

    input.read(reinterpret_cast<char *>(&headMasterNameSize), sizeof(size_t));
    headMasterName.resize(headMasterNameSize);
    input.read(&headMasterName[0], static_cast<std::streamsize>(headMasterNameSize));

    input.read(reinterpret_cast<char *>(&headMasterEmailSize), sizeof(size_t));
    headMasterEmail.resize(headMasterEmailSize);
    input.read(&headMasterEmail[0], static_cast<std::streamsize>(headMasterEmailSize));

    input.read(reinterpret_cast<char *>(&headMasterPhoneSize), sizeof(size_t));
    headMasterPhone.resize(headMasterPhoneSize);
    input.read(&headMasterPhone[0], static_cast<std::streamsize>(headMasterPhoneSize));

    headMaster.setName(headMasterName);
    headMaster.setEmail(headMasterEmail);
    headMaster.setPhoneNumber(headMasterPhone);

    // Read Students
    size_t studentCount;
    input.read(reinterpret_cast<char *>(&studentCount), sizeof(size_t));

    students.clear();
    for (size_t i = 0; i < studentCount; i++)
    {
        size_t studentNameSize, studentEmailSize;
        string studentName, studentEmail;
        Date studentBirthday;
        Transcript transcript;

        input.read(reinterpret_cast<char *>(&studentNameSize), sizeof(size_t));
        studentName.resize(studentNameSize);
        input.read(&studentName[0], static_cast<std::streamsize>(studentNameSize));

        input.read(reinterpret_cast<char *>(&studentEmailSize), sizeof(size_t));
        studentEmail.resize(studentEmailSize);
        input.read(&studentEmail[0], static_cast<std::streamsize>(studentEmailSize));

        // Read birthday safely using getters and setters
        int day, month, year;
        input.read(reinterpret_cast<char *>(&day), sizeof(int));
        input.read(reinterpret_cast<char *>(&month), sizeof(int));
        input.read(reinterpret_cast<char *>(&year), sizeof(int));

        studentBirthday.setDate(Date(day, month, year));

        // Read transcript
        input.read(reinterpret_cast<char *>(&transcript), sizeof(Transcript));

        // Create Student object
        Student newStudent;
        newStudent.setName(studentName);
        newStudent.setEmail(studentEmail);
        newStudent.setBirthday(studentBirthday);
        newStudent.setTranscript(transcript);

        students.push_back(newStudent);
    }

    input.close();
    return true;
}

