#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;


void insertionSort(vector<int>& a){
    int n=a.size();
    for(int i=0;i<n;i++){
        int key=a[i];
        int j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1] = a[j]; j--;
        }
        a[j+1] = key;
    }
}

int partition(vector<int>& a, int low, int high){
    int lt = low, gt = high;
    int pivot = a[low]; //chọn pivot là phần tử đầu tiên
    int i=low;
    for(i=low;i<=high;i++){
        if(a[i]<pivot) swap(a[lt++], a[i]);
        else if(a[i]>pivot) swap(a[i--], a[gt--]);
    }

    return min(high, lt+1);
}


// int fastThreeWayPartition(vector<int>& a, int low, int high){

// }


void quickSort(vector<int>& a, int low, int high){
    if(low<high){
        int p = partition(a, low, high);
        quickSort(a, low, p-1);
        quickSort(a, p+1, high);
    }
}


int main() {    

    int n=1000;
    vector<int> a(n,0);
    srand(time(NULL));
    for(int i=0;i<n;i++){
        a[i] = rand()%10000;
    }
    quickSort(a, 0, a.size()-1);

    for(int i=0;i<a.size()-1;i++){
        if(a[i]>a[i+1]){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    
    
    return 0;
}