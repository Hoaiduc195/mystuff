#ifndef FUNCTION
#define FUNCTION

#include <iostream>
#include <cstring>
#include <windows.h>
#include <cstdlib> 
#include <ctime>    
using namespace std;

//Rules
void generateWorld(bool **&WORLD, const unsigned int gridHeight, const unsigned int gridWidth);
void setRules(bool **&WORLD, const unsigned int gridHeight, const unsigned int gridWidth);
void display(bool **&WORLD, const unsigned int gridHeight, const unsigned int gridWidth);
void clearWorld(bool **&WORLD, const unsigned int gridHeight);

#endif