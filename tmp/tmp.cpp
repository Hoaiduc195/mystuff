#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;
// insertion sort

void insertionSort(vector<int> &nums)
{
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        int j = i - 1;
        int key = nums[i];
        while (j >= 0 && nums[j] > key)
        {
            nums[j + 1] = nums[j];
        }
        nums[j + 1] = key;
    }
}

// selection sort

void selectionSort(vector<int> &nums)
{
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        int idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] < nums[idx])
                idx = j;
        }
        if (idx != i)
            swap(nums[idx], nums[i]);
    }
}

// merge sort

void merge(vector<int> &nums, int l, int m, int r)
{
    vector<int> left(nums.begin() + l, nums.begin() + m + 1);
    vector<int> right(nums.begin() + m + 1, nums.begin() + r + 1);

    int i = 0, j = 0, k = l;
    while (i < left.size() && j < right.size())
    {
        if (nums[i] < nums[j])
            nums[k++] = left[k++];
        else
            nums[k++] = right[j++];
    }

    while (i < left.size())
        nums[k++] = left[i++];
    while (j < right.size())
        nums[k++] = right[j++];
}

void inPlaceMerge(vector<int> &nums, int l, int m, int r)
{
    int s2 = m + 1;
    if (nums[m] <= nums[s2])
        return;

    while (l <= m && s2 <= r)
    {
        if (nums[l] <= nums[s2])
            l++;
        else
        {
            int val = nums[s2];
            int idx = s2;

            while (idx != l)
            {
                nums[idx] = nums[idx - 1];
                idx--;
            }

            nums[l] = val;
            l++;
            m++;
            s2++;
        }
    }
}

void mergeSort(vector<int> &nums, int l, int r)
{
    if (l >= r)
        return;

    int m = (r + l) / 2;

    mergeSort(nums, l, m);
    mergeSort(nums, m + 1, r);

    merge(nums, l, m, r);
}

// heap sort

void heapify(vector<int> &nums, int heapSize, int i)
{
    int lar = i;
    int l = i * 2 + 1;
    int r = i * 2 + 2;

    if (l < heapSize && nums[lar] < nums[l])
        swap(lar, l);

    if (r < heapSize && nums[lar] < nums[r])
        swap(lar, r);

    if (lar != i)
    {
        swap(nums[lar], nums[i]);
        heapify(nums, heapSize, lar);
    }
}

void heapSort(vector<int> &nums)
{
    int n = nums.size();

    // build max-heap tree
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(nums, n, i);

    for (int i = n - 1; i >= 0; --i)
    {
        swap(nums[0], nums[i]);
        heapify(nums, i, 0);
    }

    for (int x : nums)
        cout << x << endl;
}

// quick sort

// Lomuto patrition (always choose the last element)
int patrition(vector<int> &nums, int p, int r){
    int i=p-1;
    int pivot = nums[r];
    for(int j=p;j<r;j++){
        if(nums[j]<=pivot)
            swap(nums[++i], nums[j]);
    }
    swap(nums[r], nums[++i]);
    return i;
}

void quickSort(vector<int>& nums, int l, int r){
    if(l>=r) return;

    int p = patrition(nums, l, r);
    quickSort(nums, l, p-1);
    quickSort(nums, p+1, r);
}
// radix sort
/*Radix sort is an algorithm base on count sort, known that every digits in a number is in range 0-9, we can sort an array of numbers by using count sort for each digits having same level in that number.*/
void radix_countSort(vector<int> &nums, int exp)
{
    vector<int> count(10, 0);
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        count[(nums[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    vector<int> ans(nums.size(), 0);
    for (int i = n - 1; i >= 0; i--)
    {
        ans[--count[((nums[i] / exp) % 10)]] = nums[i];
    }
    nums = ans;
}
void radixSort(vector<int> &nums)
{
    int m = *max_element(begin(nums), end(nums));
    for (int exp = 1; m / exp > 0; exp *= 10)
    {
        radix_countSort(nums, exp);
    }
}

void binaryCountSort(vector<int> &nums, int pos)
{
    int count[2] = {0};
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        count[((nums[i] >> pos) & 1)]++;
    }

    count[1] += count[0];
    vector<int> ans(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        ans[--count[(nums[i] >> pos) & 1]] = nums[i];
    }
    nums = ans;
}

void binaryRadixSort(vector<int> &nums)
{
    int m = *max_element(begin(nums), end(nums));
    int i = 0;
    while (m)
    {
        binaryCountSort(nums, i++);
        m >>= 1;
    }
}

// count sort
void countSort(vector<int> &nums)
{
    int MIN = INT_MAX;
    int MAX = INT_MIN;

    for (int x : nums)
    {
        MIN = min(MIN, x);
        MAX = max(MAX, x);
    }
    vector<int> range(MAX - MIN + 1, 0);

    for (int i = 0; i < nums.size(); i++)
    {
        range[nums[i] - MIN]++;
    }
    int idx = 0;
    for (int i = 0; i < range.size(); i++)
    {
        while (range[i]--)
        {
            nums[idx++] = i + MIN;
        }
    }

    for (int x : nums)
        cout << x << " ";
    cout << endl;
}

vector<int> stableCountSort(vector<int> &inputArray)
{

    int N = inputArray.size();
    int M = 0;

    for (int i = 0; i < N; i++)
        M = max(M, inputArray[i]);

    vector<int> countArray(M + 1, 0);

    for (int i = 0; i < N; i++)
        countArray[inputArray[i]]++;

    for (int i = 1; i <= M; i++)
        countArray[i] += countArray[i - 1]; // fixing index

    vector<int> outputArray(N);
    for (int i = N - 1; i >= 0; i--)
    {
        outputArray[countArray[inputArray[i]] - 1] = inputArray[i];
        countArray[inputArray[i]]--;
    }

    return outputArray;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    quickSort(a,0, n-1);
    for(int x:a) cout<<x<<" ";
    return 0;
}