#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <vector>
#include <climits>
#include <utility>

using namespace std;

void displayEdgeList(vector<pair<int,int>> a);
void displayAdjacencyList(vector<vector<int>> a);
void displayMatrixList(vector<vector<int>> a);

vector<vector<int>> convertEgdeListToAdjacencyList(vector<pair<int,int>> a);
vector<pair<int,int>> convertAdjacencyListToEdgeList(vector<vector<int>> a);

vector<vector<int>> convertAdjacencyListToMatrix(vector<vector<int>> a);
vector<vector<int>> convertAdjacencyMatrixToList(vector<vector<int>> a);

vector<pair<int,int>> convertAdjacencyMatrixToEdgeList(vector<vector<int>> a);
vector<vector<int>> convertEdgeListToAdjacencyMatrix(vector<pair<int,int>> a);


#endif