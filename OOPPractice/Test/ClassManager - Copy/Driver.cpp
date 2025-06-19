#include "Driver.h"

Classroom bufferClassroom;

void printStartMenu()
{
    cout << "________________________________________________________________________" << endl;
    cout << "   ____ _                 __  __                                   \n";
    cout << "  / ___| | __ _ ___ ___  |  \\/  | __ _ _ __   __ _  __ _  ___ _ __ \n";
    cout << " | |   | |/ _` / __/ __| | |\\/| |/ _` | '_ \\ / _` |/ _` |/ _ \\ '__|\n";
    cout << " | |___| | (_| \\__ \\__ \\ | |  | | (_| | | | | (_| | (_| |  __/ |   \n";
    cout << "  \\____|_|\\__,_|___/___/ |_|  |_|\\__,_|_| |_|\\__,_|\\__, |\\___|_|   \n";
    cout << "                                                   |___/           \n";
    cout << "________________________________________________________________________" << endl;
    cout << "                                                 - Made by Duckie -       " << endl;
    

    printMainMenu();
}

bool isValidEmail(const string &mail)
{
    // Chat GPT
    const regex pattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    return regex_match(mail, pattern);
}

Student inputStudent()
{
    Student bufferStudent;
    string nameBuffer = "", emailBuffer = "";
    cout << "Name: ";
    cin.ignore();
    getline(cin, nameBuffer);
    transform(nameBuffer.begin(), nameBuffer.end(), nameBuffer.begin(), ::toupper);
    bufferStudent.setName(nameBuffer);

    do
    {
        if (emailBuffer != "")
            cout << "Invalid email." << endl;
        cout << "Email: ";
        cin >> emailBuffer;
    } while (!isValidEmail(emailBuffer));
    bufferStudent.setEmail(emailBuffer);

    Date bufferBirthday(1, 1, 1);
    do
    {
        int d, m, y;
        cout << "Birthday: " << endl;
        cout << "Day: ";
        cin >> d;
        cout << "Month: ";
        cin >> m;
        cout << "Year: ";
        cin >> y;
        bufferBirthday.setDate({d, m, y});
    } while (!bufferBirthday.isValidDate());
    bufferStudent.setBirthday(bufferBirthday);

    string configTranscriptAnswer;
    cout << "Do you want to config transcript? (Y/N)";
    cin >> configTranscriptAnswer;
    if (configTranscriptAnswer == "Y")
    {
        cout << "Input Mathematic, Physics, Chemistry, English Points Respectively: ";
        double m, p, c, e;
        cin >> m >> p >> c >> e;
        Transcript newTranscript(m, p, c, e);
        bufferStudent.setTranscript(newTranscript);
    }
    else
    {
        bufferStudent.setTranscript({0.0, 0.0, 0.0, 0.0});
    }

    return bufferStudent;
}

Teacher inputNewHeadMaster()
{
    Teacher newHeadMaster;
    string nameBuffer = "", emailBuffer = "", phoneNumberBuffer = "";
    cout << "Name: ";
    cin.ignore();
    getline(cin, nameBuffer);
    transform(nameBuffer.begin(), nameBuffer.end(), nameBuffer.begin(), ::toupper);
    newHeadMaster.setName(nameBuffer);
    
    do
    {
        if (emailBuffer != "")
            cout << "Invalid Email." << endl;
        cout << "Email: ";
        cin >> emailBuffer;

    } while (!isValidEmail(emailBuffer));
    newHeadMaster.setEmail(emailBuffer);
    do
    {
        if (phoneNumberBuffer != "")
            cout << "Invalid phone number." << endl;
        cout << "Phone Number: ";
        cin >> phoneNumberBuffer;
    } while (!isValidPhoneNumber(phoneNumberBuffer));

    newHeadMaster.setPhoneNumber(phoneNumberBuffer);
    return newHeadMaster;
}

void printHeadMasterAdjustMenu()
{
    int input = 1;
    // Teacher* headMaster = bufferClassroom.getHeadMaster();

    Teacher headMaster = bufferClassroom.getHeadMaster();
    while (input)
    {
        cout << "+-----------------------------------------------------+" << endl;
        cout << "|                    CONFIG HEADMASTER                |" << endl;
        cout << "+-----------------------------------------------------+" << endl;
        cout << "|          1. Change Name.                            |" << endl;
        cout << "|          2. Change Email.                           |" << endl;
        cout << "|          3. Change Phone Number.                    |" << endl;
        cout << "|          0. Exit.                                   |" << endl;
        cout << "+-----------------------------------------------------+" << endl;

        cout << "Input your choice: ";
        if (!(cin >> input)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number." << endl;
            system("pause");
            continue;
        }

        switch (input)
        {
        case 1:
        {
            string newName;
            cout << "Name: ";
            cin.ignore();
            getline(cin, newName);
            headMaster.setName(newName);
            break;
        }

        case 2:
        {
            string newEmail = "";
            do
            {
                if (newEmail != "")
                    cout << "Invalid Email." << endl;
                cin >> newEmail;
            } while (!isValidEmail(newEmail));

            headMaster.setEmail(newEmail);
            break;
        }
        case 3:
        {
            string newPhoneNumber = "";
            do
            {
                if (newPhoneNumber != "")
                    cout << "Invalid Phone Number." << endl;
                cin >> newPhoneNumber;
            } while (!isValidPhoneNumber(newPhoneNumber));

            headMaster.setPhoneNumber(newPhoneNumber);
            break;
        }

        case 0:
        {
            input = 0;
            break;
        }

        default:
        {
            input = 0;
            break;
        }
        }
    }
    bufferClassroom.setHeadMaster(headMaster);
}

void printManipulateStudentInterface(int idx)
{
    int input = 1;
    // Student *bufferStudent = bufferClassroom.getStudentIndex(idx);
    Student newGuy = bufferClassroom.getOneGuy(idx);
    while (input)
    {
        cout << "+-----------------------------------------------------+" << endl;
        cout << "|                    CONFIG STUDENT                   |" << endl;
        cout << "+-----------------------------------------------------+" << endl;
        cout << "|          1. Change Name.                            |" << endl;
        cout << "|          2. Change Birthday.                        |" << endl;
        cout << "|          3. Change Email.                           |" << endl;
        cout << "|          4. Adjust Transcript.                      |" << endl;
        cout << "|          0. Exit.                                   |" << endl;
        cout << "+-----------------------------------------------------+" << endl;

        cout << "Input your choice: ";
        if (!(cin >> input)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number." << endl;
            system("pause");
            continue;
        }

        switch (input)
        {
        case 1:
        {
            cout << "New Name: ";
            string newName;
            cin.ignore();
            getline(cin, newName);
            newGuy.setName(newName);
            break;
        }
        case 2:
        {
            Date tmp;
            int d = INT_MIN, m = INT_MIN, y = INT_MIN;
            do
            {
                if (d != INT_MIN || m != INT_MIN || y != INT_MIN)
                    cout << "Invalid value." << endl;

                cin >> d >> m >> y;
                tmp = {d, m, y};
            } while (!tmp.isValidDate());

            tmp = {d, m, y};
            newGuy.setBirthday(tmp);
            break;
        }
        case 3:
        {
            string newEmail = "";
            do
            {
                if (newEmail != "")
                    cout << "Invalid Email." << endl;
                cin >> newEmail;
            } while (!isValidEmail(newEmail));
            newGuy.setEmail(newEmail);
            break;
        }
        case 4:
        {
            newGuy.adjustTranscript();
            break;
        }
        case 0:
        {
            input = 0;
            break;
        }
        default:
        {
            input = 0;
            break;
        }
        }
    }

    bufferClassroom.swapGuyWith(idx, newGuy);
}

void printClassManipulationMenu()
{

    int input;
    while (input)
    {
        cout << "+-----------------------------------------------------+" << endl;
        cout << "|                    CLASS MENU                       |" << endl;
        cout << "+-----------------------------------------------------+" << endl;
        cout << "|      1. Change HeadMaster.                          |" << endl;
        cout << "|      2. Classroom List.                             |" << endl;
        cout << "|      3. Add Students.                               |" << endl;
        cout << "|      4. Remove Students.                            |" << endl;
        cout << "|      5. Sorted List.                                |" << endl;
        cout << "|      6. Manipulate On Student.                      |" << endl;
        cout << "|      7. Adjust HeadMaster's Information.            |" << endl;
        cout << "|      0. Exit.                                       |" << endl;
        cout << "+-----------------------------------------------------+" << endl;

        cout << "Input your choice: ";
        if (!(cin >> input)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number." << endl;
            system("pause");
            continue;
        }

        switch (input)
        {
        case 1:
        {
            cout << "_New HeadMaster Information_" << endl;
            Teacher newHeadMaster = inputNewHeadMaster();
            bufferClassroom.setHeadMaster(newHeadMaster);
            break;
        }
        case 2:
        {
            bufferClassroom.displayClass();
            break;
        }
        case 3:
        {
            int newStudentNumber = INT_MIN;
            do
            {
                if (newStudentNumber != INT_MIN)
                    cout << "Invalid value." << endl;
                cout << "Input number of students to add in class: ";
                cin >> newStudentNumber;
            } while (newStudentNumber < 0);

            for (int i = 0; i < newStudentNumber; i++)
            {
                Student bufferStudent = inputStudent();
                bufferClassroom.addStudent(bufferStudent);
            }
            bufferClassroom.sortByName();

            break;
        }
        case 4:
        {
            int removeStudentNumber = INT_MIN;
            do
            {
                if (removeStudentNumber != INT_MIN)
                    cout << "Invalid value." << endl;
                cout << "Input number of students to remove from class: ";
                cin >> removeStudentNumber;
            } while (removeStudentNumber < 0);
            for (int i = 0; i < removeStudentNumber; i++)
            {
                cout << "Current List: " << endl;
                bufferClassroom.displayClass();
                int idx;
                cin >> idx;
                bufferClassroom.removeStudent(idx);
            }
            break;
        }
        case 5:
        {
            printSortMenu();
            break;
        }
        case 6:
        {
            int idx = INT_MIN;
            do
            {
                if (idx != INT_MIN)
                    cout << "Invalid value." << endl;
                cout << "Input ID (index) of students: ";

                cin >> idx;
            } while (idx < 0 || idx >= bufferClassroom.getClassSize());

            printManipulateStudentInterface(idx);

            break;
        }
        case 7:
        {
            printHeadMasterAdjustMenu();
            break;
        }
        case 0:
        {
            input = 0;
            break;
        }
        default:
        {
            input = 0;
            break;
        }
        }
    }

    //Saving new state to old file.
    string currentFilename = bufferClassroom.getFileName();
    if(bufferClassroom.saveToFile(currentFilename)){
        cout<<"Successfully save changes."<<endl;
    }else cout<<"Fail in saving changes"<<endl;

    bufferClassroom.clear();
}

void printSortMenu()
{
    int sortChoice = 1;
    Classroom IdenticalClassroom = bufferClassroom;
    while (sortChoice)
    {
        cout << "+-----------------------------------------------------+" << endl;
        cout << "|                    SORT MENU                        |" << endl;
        cout << "+-----------------------------------------------------+" << endl;
        cout << "|          1. Sort By GPA.                            |" << endl;
        cout << "|          2. Sort By Birthday.                       |" << endl;
        cout << "|          0. Exit.                                   |" << endl;
        cout << "+-----------------------------------------------------+" << endl;

        cout << "Your choice: ";
        if (!(cin >> sortChoice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number." << endl;
            system("pause");
            continue;
        }

        switch (sortChoice)
        {
        case 1:
        {
            IdenticalClassroom.sortByGPA();

            vector<Student> IdenticalStudentList = IdenticalClassroom.getStudents();

            cout << "_______________________________________________________" << endl;
            for (size_t i = 0; i < IdenticalStudentList.size(); i++)
            {
                cout << setw(25) << IdenticalStudentList[i].getName() << setw(4) << IdenticalStudentList[i].getGPA() << endl;
            }
            cout << "_______________________________________________________" << endl;

            break;
        }

        case 2:
        {
            IdenticalClassroom.sortByBirthday();

            vector<Student> IdenticalStudentList = IdenticalClassroom.getStudents();

            cout << "_______________________________________________________" << endl;
            for (size_t i = 0; i < IdenticalStudentList.size(); i++)
            {
                cout << setw(25) << IdenticalStudentList[i].getName() << setw(4) << IdenticalStudentList[i].getBirthday() << endl;
            }
            cout << "_______________________________________________________" << endl;
            break;
        }
        case 0:
        {
            sortChoice = 0;
            break;
        }
        default:
        {
            sortChoice = 0;
            break;
        }
        }
    }
}

void printLoadFileInterface()
{
    string filename;
    cout << "Input filename (INPUT ZERO TO EXIT): ";
    cin >> filename;
    if (filename == "0")
        return;

    if (!bufferClassroom.readFile(filename))
    {
        cout << "Can not open file: " << filename;
        system("pause");
        system("clear");
        printLoadFileInterface();
    }
    else
    {
        cout << "Successfully read file: " << filename << "." << endl;
        system("pause");
        system("clear");
        printClassManipulationMenu();
    }

    printMainMenu();
}

/*____________________________________________________________________________________________________________*/
// Above is the class manipulate session, Below I intend to build another branch of menu, some new features such as create new class and save that new into a binary file.
void printCreateNewClassroomInterface()
{
    int numberOfStudent = INT_MIN;
    bufferClassroom.clear();

    cout << "_______________________________________________________" << endl;
    cout << "---HEADMASTER'S INFORMATION---" << endl;
    Teacher headMaster = inputNewHeadMaster();
    bufferClassroom.setHeadMaster(headMaster);

    cout << "_______________________________________________________" << endl;
    cout << "INPUT NUMBER OF STUDENT IN NEW CLASSROOM: ";

    do
    {
        if (numberOfStudent != INT_MIN)
            cout << "Invalid value." << endl;
        cin >> numberOfStudent;
    } while (numberOfStudent < 0);

    for (int i = 0; i < numberOfStudent; i++)
    {
        Student student = inputStudent();
        bufferClassroom.addStudent(student);
    }

    cout << "Successfully create new classroom. Would you like to save it? (Y?N)" << endl;
    string answer;
    cin >> answer;
    if (answer == "Y")
    {
        printSaveClassroomToFileInterface();
    }
    else
    {
        cout << "Don't save new classroom? (Y?N)" << endl;
        cin >> answer;
        if (answer == "Y")
        {
            printSaveClassroomToFileInterface();
        }
    }
    printMainMenu();
}

void printSaveClassroomToFileInterface()
{
    string filename;
    cout << "_________________SAVE_YOUR_CLASSROOM___________________" << endl;
    cout << "Save as name: ";
    do
    {
        cin >> filename;
        string suffix = filename.substr(filename.size() - 4);
        if(suffix == ".bin") break;
        else cout<<"Binary file required."<<endl;
    } while (true);

    if(bufferClassroom.saveToFile(filename)){
        cout<<"Successfully save file."<<endl;
    }else{
        cout<<"Fail to save file. Please double check again."<<endl;
        cout<<"Regenerate saving procedure? (Y/N)";
        string ans; cin>>ans;
        if(ans == "Y") printSaveClassroomToFileInterface();
    }

    printMainMenu();    
}


/*____________________________________________________________________________________________________________________*/
//Above is the second session of the main menu.

void printMainMenu()
{
    int input;

    cout << "+-----------------------------------------------------+" << endl;
    cout << "|                         MENU                        |" << endl;
    cout << "+-----------------------------------------------------+" << endl;
    cout << "|        1. Load File Classroom.                      |" << endl;
    cout << "|        2. Create New Classroom.                     |" << endl;
    cout << "|        0. Exit.                                     |" << endl;
    cout << "+-----------------------------------------------------+" << endl;
    cout<<"Input: "; 
    if (!(cin >> input)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input!" << endl;
        system("pause");
        return;
    }

    switch(input){
        case 1:
        {
            printLoadFileInterface();
            break;
        }
        case 2:
        {
            printCreateNewClassroomInterface();
            break;
        }

        case 0:
        {
            exit(0);
        }

        default:
        {
            exit(0);
        }
    }

}