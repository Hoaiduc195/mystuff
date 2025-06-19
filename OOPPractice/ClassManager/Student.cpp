#include "Student.h"


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
    output<<name<<": ";
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
    return sum/4.0;
}
