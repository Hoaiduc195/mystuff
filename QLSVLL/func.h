#ifndef __MYFUNC
#define __MYFUNC

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

struct Student
{
    char ID[100];
    char name[100];
    unsigned int age;

    Student(const char a[], const char b[], const unsigned int c)
    {
        strcpy(ID, a);
        strcpy(name, b);
        age = c;
    }
    Student() : ID(""), name(""), age(0) {};
};

struct Node
{
    Student data;
    Node *next;
};

struct StudentList
{
    Node *head;
    Node *tail;
};

Student inputData();
Node *createNode(Student q);
void initList(StudentList &list);
void addTail(StudentList &list, Student p);
void rmHead(StudentList &list);
void rmAll(StudentList &list);
void displayStudent(Student p);
void displayList(StudentList list);
void loadToFileBin(char fileName[], StudentList list);
void readFromFileBin(char path[], StudentList &list);
void readFromFileText(char path[], StudentList list);
void loadToFileText(char path[], StudentList list);

#endif