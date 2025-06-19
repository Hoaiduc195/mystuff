#ifndef _DRIVER_H_
#define _DRIVER_H_

#include "Classroom.h"
#include "Date.h"
#include "Student.h"
#include "Teacher.h"
#include <climits>

Classroom bufferClassroom;

bool isValidEmail(const string &mail);
bool isValidPhoneNumber(const string &phoneNumber);
/*________________________________________________________*/
Student inputStudent();
Teacher inputNewHeadMaster();
/*________________________________________________________*/
void printHeadMasterAdjustMenu();
void printManipulateStudentInterface(int idx);
void printStartMenu();
void printClassManipulationMenu();
void printSortMenu();
void printLoadFileInterface();
void printCreateNewClassroomInterface();
void printSaveClassroomToFileInterface();
void printMainMenu();


#endif
