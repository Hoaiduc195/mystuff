#ifndef _DRIVER_H_
#define _DRIVER_H_

#include "Classroom.h"
#include "Date.h"
#include <climits>

bool isValidEmail(const string &mail);
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
