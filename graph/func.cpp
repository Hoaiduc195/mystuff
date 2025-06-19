#include "func.h"


void displayEdgeList(vector<pair<int,int>> a){
    for(size_t i=0;i<a.size();i++){
        cout<<"["<<a[i].first<<" , "<<a[i].second<<"]"<<endl;
    }
}

void displayAdjacencyList(vector<vector<int>> a){
    for(size_t i=0;i<a.size();i++){
        cout<<i<<": ";
        for(const auto& e:a[i]){
            cout<<e<<" ";
        }
        cout<<endl;
    }
}

void displayMatrixList(vector<vector<int>> a){
    for(size_t i=0;i<a.size();i++){
        for(size_t j = 0;j<a.size();j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

vector<vector<int>> convertEgdeListToAdjacencyList(vector<pair<int,int>> a){
    size_t size = a.size();
    int MAX = INT_MIN;
    for(int i=0;i<size;i++){
        MAX = max(MAX,max(a[i].first,a[i].second));
    }
    vector<vector<int>> AList(MAX+1);
    for(int i=0;i<size;i++){
        Alist[a[i].first].push_back(a[i].second);
        Alist[a[i].second].push_back(a[i].first); // undirected graph
    }
    return AList;
}

vector<pair<int,int>> convertAdjacencyListToEdgeList(vector<vector<int>> a){
    size_t r = a.size();
    if(!r){
        return {{}};
    }
    size_t c = a[0].size();
    vector<pair<int,int>> EList;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            Elist.emplace_back(i,j);
        }
    }
    return EList;
}

vector<vector<int>> convertAdjacencyListToMatrix(vector<vector<int>> a){
    vector<vector<int>> M(a.size(),vector<int>(a.size(),0));

    for(size_t i=0;i<a.size();i++){
        for(size_t j=0;j<a[i].size();j++){
            M[i][a[i][j]] = 1;
            M[a[i][j]][i] = 1; // undirected graph
        }
    }
    return M;
}

vector<vector<int>> convertAdjacencyMatrixToList(vector<vector<int>> a){
    vector<vector<int>> AList(a.size());

    for(int i =0;i<a.size();i++){
        for(int j=0;j<a.size();j++){
            if(a[i][j]) Alist[i].push_back(j);
        }
    }
}

vector<pair<int,int>> convertAdjacencyMatrixToEdgeList(vector<vector<int>> a){
    vector<pair<int,int>> EList;
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a.size();j++){
            if(a[i][j]) Elist.emplace_back(i,j);
        }
    }
    return Elist;
}

vector<vector<int>> convertEdgeListToAdjacencyMatrix(vector<pair<int,int>> a){
    int MAX = INT_MIN;
    for(int i=0;i<a.size();i++){
        MAX = max(a[i].first);
    }
    vector<vector<int>> M(MAX+1,vector<int>(MAX+1,0));

    for(int i=0;i<a.size();i++){
        M[a[i].first][a[i].second] = 1;
    }

    return M;
}



