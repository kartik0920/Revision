#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void printArr(vector<int> arr)
{
    cout << "This is array:";
    for (auto i : arr)
    {
        cout << i << ' ';
    }
    cout << endl;
}

int getPartition(vector<int> &arr, int s, int e)
{
    int count = 0;
    for (int i = s; i <= e; i++)
    {
        if (arr[i] < arr[s])
        {
            count++;
        }
    }
    int pivot_index = count + s;
    swap(arr[s], arr[pivot_index]);
    int i = s, j = e;
    while (j >= i)
    {
        while (arr[i] < arr[pivot_index])
        {
            i++;
        }
        while (arr[j] > arr[pivot_index])
        {
            j--;
        }
        if (j >= i)
        {
            swap(arr[j--], arr[i++]);
        }
    }
    return pivot_index;
}
void quickSort(vector<int> &arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int pivot = getPartition(arr, s, e);
    quickSort(arr, s, pivot - 1);
    quickSort(arr, pivot + 1, e);
}

int main()
{
    vector<int> arr = {43, 1, 5, 1, 2, 4};
    int s = 0, e = arr.size() - 1;
    printArr(arr);
    quickSort(arr, s, e);
    printArr(arr);

    return 0;
}