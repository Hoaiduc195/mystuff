#include <iostream>
#include <vector>
#include <cmath>
#include <utility>

using namespace std;

const int INSERTION_THRESHOLD = 16;

inline void printSwap(vector<int> &a, int i, int j, bool print = true)
{
    int idx1 = (i < j ? i : j);
    int idx2 = (i < j ? j : i);
    if (print && (idx1 != idx2))
        cout << idx1 << " " << idx2 << endl;
    swap(a[idx1], a[idx2]);
}

void insertionSort(vector<int> &a, int low, int high)
{
    for (int i = low; i <= high; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= low && a[j] > key)
        {
            printSwap(a, j + 1, j);
            j--;
        }
        a[j + 1] = key;
    }
}

int medianOfThree(vector<int> &a, int low, int high) {
    int mid = low + (high - low) / 2;
    if ((a[low] <= a[mid] && a[mid] <= a[high]) || (a[high] <= a[mid] && a[mid] <= a[low]))
        return mid;
    if ((a[mid] <= a[low] && a[low] <= a[high]) || (a[high] <= a[low] && a[low] <= a[mid]))
        return low;
    return high;
}
int partition_median(vector<int> &a, int low, int high)
{
    int pivotIdx = medianOfThree(a, low, high);
    int pivot = a[pivotIdx];
    int i = low;
    swap(a[low], a[pivotIdx]);
    for (int j = low; j <= high; j++)
    {
        if (a[j] < pivot)
        {
            swap(a[j], a[++i]);
        }
    }

    swap(a[i], a[low]);
    return i;
}

void heapify_segment(vector<int> &a, int start, int end, int root)
{
    int lar = root;
    int c1 = 2 * root + 1;
    int c2 = 2 * root + 2;

    if (c1 <= end && a[lar] < a[c1])
        swap(c1, lar);
    if (c2 <= end && a[lar] < a[c2])
        swap(c2, lar);

    if (lar != root)
    {
        // swap(a[lar], a[root]);
        printSwap(a, lar, root);
        heapify_segment(a, start, end, lar);
    }
}

void heapSort_segment(vector<int> &a, int start, int end)
{
    for (int i = (end + 1 + start) / 2 - 1; i >= start; i--)
    {
        heapify_segment(a, start, end, i);
    }

    for (int i = end; i >= start; i--)
    {
        // swap(a[start], a[i]);
        printSwap(a, start, i);
        heapify_segment(a, start, i, start);
    }
}

void introsort_util(vector<int> &a, int start, int end, int depthLimit)
{
    int size = end - start + 1;
    if (size <= INSERTION_THRESHOLD)
    {
        insertionSort(a, start, end);
        return;
    }
    if (depthLimit == 0)
    {
        heapSort_segment(a, start, end);
        return;
    }
    int p = partition_median(a, start, end);
    cout << p << endl;

    introsort_util(a, start, p - 1, depthLimit - 1);
    introsort_util(a, p + 1, end, depthLimit - 1);
}

void introsort(vector<int> &a)
{
    int n = a.size();
    int depthLimit = 2 * (int)(floor(log2(n)));
    introsort_util(a, 0, n - 1, depthLimit);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // #ifndef MYIO
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    int n
    if (!(cin >> n))
        return 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    introsort(a);

    // for(int x:a) cout<<x<<" ";
    // cout<<endl;
    return 0;
}