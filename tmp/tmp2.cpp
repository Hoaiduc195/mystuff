#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;
// insertion sort

void insertionSort(vector<int>& nums){
    int n=nums.size();
    for(int i=0;i<n;i++){
        int j=i-1;
        int key=nums[i];
        while(j>=0 && nums[j]>key){
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = key;
    }
}
// selection sort
void selectionSort(vector<int>& nums){
    int n=nums.size();
    for(int i=0;i<n;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(nums[j]<nums[min]) min=j;
        }
        if(i!=min) swap(nums[i], nums[min]);
    }
}


// merge sort
void inPlaceMerge(vector<int> &nums, int l, int m, int r){
    int s2 = m+1;
    if(nums[m]<=nums[s2]) return;

    while(l<=m && s2<=r){
        if(nums[l]<=nums[s2]){
            l++;
        }else{
            int val = nums[s2];
            int j=s2-1;
            while(j>=l){
                nums[j+1]=nums[j];
                j--;
            }
            nums[l] = val;

            l++; s2++; m++;
        }
    }
}

void merge(vector<int> &nums, int l, int m, int r){
    vector<int> left(nums.begin()+l, nums.begin()+m+1);
    vector<int> right(nums.begin()+m+1, nums.begin()+r+1);


    int i=0,j=0,k=l;

    while(i<left.size() && j<right.size()){
        if(left[i]<=right[j]) nums[k++] = left[i++];
        else nums[k++]=right[j++]; 
    }

    while(i<left.size()) nums[k++]=left[i++];
    while(j<right.size()) nums[k++]=right[j++];
}

void mergeSort(vector<int> &nums, int l, int r){
    if(l<r){
        int m=(r+l)/2;

        mergeSort(nums, l, m);
        mergeSort(nums, m+1, r);
        merge(nums, l,m,r);
    }
}

// heap sort
void heapify(vector<int> &nums, int heapSize, int i){
    int lar=i;
    int c1=i*2+1;
    int c2=i*2+2;

    if(c1<heapSize && nums[lar]<nums[c1]) swap(c1,lar);

    if(c2<heapSize && nums[lar]<nums[c2]) swap(c2, lar);


    if(lar!=i){
        swap(nums[lar], nums[i]);
        heapify(nums, heapSize, lar);
    }
}

void heapSort(vector<int> &nums){
    int n=nums.size();

    for(int i=n/2-1;i>=0;--i){
        heapify(nums, n, i);
    }

    for(int i=n-1;i>=0;i--){
        swap(nums[0], nums[i]);
        heapify(nums, i, 0);
    }
}

// quick sort
int patrition(vector<int>& nums, int l, int r){
    int pivot = nums[r]; // Lomuto patrition
    int i=l-1;
    for(int j=l;j<r;j++){
        if(nums[j]<pivot) swap(nums[++i], nums[j]);
    }   

    swap(nums[++i], nums[r]);
    return i;
}

int hoarePatition(vector<int> &nums, int l, int r){
    int i=l-1;
    int j=r+1;
    int pivot=nums[l];

    while(true){
        do{ ++i; }while(nums[i]<pivot);
        do{ --j; }while(nums[j]>pivot);

        if(i<j) swap(nums[i], nums[j]);
        else return j;
    }
    return 0;
}

void quickSort(vector<int> &nums, int l, int r){
    if(l>=r) return;

    int p = hoarePatition(nums, l, r);
    quickSort(nums, l, p);
    quickSort(nums, p+1, r);
}
// radix sort
/*Radix sort is an algorithm base on count sort, known that every digits in a number is in range 0-9, we can sort an array of numbers by using count sort for each digits having same level in that number.*/

void decimalCountSort(vector<int> &nums, int exp){
    int count[10] = {0};
    int n=nums.size();
    for(int i=0;i<n;i++){
        count[(nums[i]/exp)%10]++;
    }

    for(int i=1;i<10;i++) count[i]+=count[i-1];

    vector<int> ans=nums;
    for(int i=n-1;i>=0;i--) ans[--count[(nums[i]/exp)%10]] = nums[i];
    nums=ans;
}

void radixSort(vector<int>& nums){
    int m=*max_element(nums.begin(), nums.end());

    for(int exp=1;m/exp;exp*=10){
        decimalCountSort(nums, exp);
    }
}

void binaryCountSort(vector<int>& nums, int pos){
    int count[2] = {0};
    int n=nums.size();
    for(int i=0;i<n;i++) count[(nums[i]>>pos)&1]++;

    count[1]+=count[0];

    vector<int> ans = nums;
    for(int i=n-1;i>=0;i--){
        ans[--count[(nums[i]>>pos)&1]]=nums[i];
    }

    nums=ans;
}

void binaryRadixSort(vector<int> &nums){
    int m = *max_element(nums.begin(), nums.end());
    
    int pos=0;
    while(m){
        binaryCountSort(nums, pos);
        m>>=1;
    }
}

// count sort
void countSort(vector<int>& nums){
    int MIN = *min_element(nums.begin(), nums.end());
    int MAX = *max_element(nums.begin(), nums.end());
    int n=nums.size();
    vector<int> count(MAX-MIN+1, 0);
    for(int x:nums) count[x - MIN]++;
    for(int i=1;i<count.size();i++) count[i]+=count[i-1];
    vector<int> ans=nums;

    for(int i=n-1;i>=0;i--){
        ans[--count[nums[i] - MIN]] = nums[i];
    }
    nums=ans;
}


int main()
{

    freopen("output.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    quickSort(a, 0, n-1);
    for(int x:a) cout<<x<<endl;

    for(int i=0;i<a.size()-1;i++) if(a[i]>a[i+1]){cout<<"NO"<<endl; return 0;}

    cout<<"YES"<<endl;
    return 0;
}