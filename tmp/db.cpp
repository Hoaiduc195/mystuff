#include <bits/stdc++.h>
#include <fstream>
using namespace std;

void createInput(){
    fstream input("INPUT.txt");
    if(!input.is_open()){
        cout<<"Can not open file.\n";
        return;
    }
    srand(time(NULL));
    int t = 1000;
    for(int i=0;i<t;i++){
        int n = rand()%10000;
        int a = rand()%100, b = rand()%100, c = rand()%100;
        input<<n<<" "<<a<<" "<<b<<" "<<c<<endl;
        for(int j=0;j<n;j++){
            input<<rand()%10000000<<" ";
        }
        input<<endl;
    }
}


int main() {
    
    #ifndef DBG
    freopen("q0.txt", "w", stdout);
    #endif
    
    return 0;
}