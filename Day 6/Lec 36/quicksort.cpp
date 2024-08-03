#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void printArr(vector<int> arr)
{
    cout << "Here is array : ";
    for (auto i : arr)
    {
        cout << i << ' ';
    }
    cout << endl;
}

int getpartition(vector<int> &arr, int s, int e)
{
    int cnt = 0;
    for (int i = s; i <= e; i++)
    {
        if (arr[i] < arr[s])
        {
            cnt++;
        }
    }
    int pivotindex = s + cnt;
    int pivot = arr[pivotindex];
    swap(arr[s], arr[pivotindex]);

    int i = s, j = e;
    while (j >= i)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }

        if (j >= i)
        {
            swap(arr[j--], arr[i++]);
        }
    }
    return pivotindex;
}

void quicksort(vector<int> &arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int pivot = getpartition(arr, s, e);
    quicksort(arr, s, pivot - 1);
    quicksort(arr, pivot + 1, e);
}
int main()
{
    vector<int> arr = {6, 4, 2, 8, 13, 1, 4, 6, 3};
    int s = 0, e = arr.size() - 1;
    printArr(arr);
    quicksort(arr, s, e);
    printArr(arr);
    return 0;
}