#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int partition(vector<int> &a, int low, int high)
{
    int pivot = a[low];
    int j = low;
    for (int i = low; i <= high; i++)
    {
        if (a[i] < pivot)
            swap(a[++j], a[i]);
    }

    swap(a[j], a[low]);
    return j;
}

void quickSort(vector<int> &a, int l, int h)
{
    if (l < h)
    {
        int p = partition(a, l, h);
        quickSort(a, l, p - 1);
        quickSort(a, p + 1, h);
    }
}

bool binarySearch(vector<int>& a, int x){
    int l=0, r=a.size()-1;
    

    while(l<=r){
        int m=(r+l)/2;
        if(a[m] == x) return 1;
        if(a[m]<x) l=m+1;
        else r=m-1;
    }
    return 0;
}

pair<int, int> solve(vector<int> &a, vector<int> &b, int x)
{
    
    quickSort(a, 0, a.size()-1);
    quickSort(b, 0, b.size()-1);


    for(int i=0;i<a.size();i++){
        if(binarySearch(b, x-a[i])) return {a[i], x-a[i]};
    }
    return {-1, -1};
}

int main()
{

    vector<int> a = {0, 3, 1, 6, 2, 5, 4};
    vector<int> b = {1, 0, 3, 6, 4, 2, 5};

    pair<int, int> ans = solve(a, b, 10);
    cout << ans.first << " " << ans.second << endl;
    return 0;
}