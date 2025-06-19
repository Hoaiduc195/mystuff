#include "func.h"
#include <cstring>
#include <string>
#include <sstream>

int M[1000][1000]; // Adjacency Matrix
vector<int> a[1001]; //Adjacency List
vector<pair<int,int>> e;

int main() {
    int n;
    cin>>n;
    cin.ignore();
    for(int i=1;i<=n;i++){
        string s, num;
        getline(cin,s);
        stringstream ss(s);
        while(ss>>num){
            if(stoi(num)>i){
                e.emplace_back(i,stoi(num));
            }
        }
    }

    for(const auto& p:e){
        cout<<p.first<<" "<<p.second<<endl;
    }

    
    return 0;
}