#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void printArr(vector<int> arr)
{
    cout << "Array :";
    for (auto i : arr)
    {
        cout << i << ' ';
    }
    cout << endl;
}

void merge(vector<int> &arr, int s, int e)
{
    int mid = s + (e - s) / 2;
    int l1 = mid - s + 1;
    int l2 = e - mid;

    vector<int> arr1(l1);
    vector<int> arr2(l2);

    int k = s;
    for (int i = 0; i < l1; i++)
    {
        arr1[i] = arr[k++];
    }

    k = mid + 1;

    for (int i = 0; i < l2; i++)
    {
        arr2[i] = arr[k++];
    }
    int i = 0, j = 0;
    k = s;
    while (i < l1 && j < l2)
    {
        if (arr1[i] < arr2[j])
        {
            arr[k++] = arr1[i++];
        }
        else
        {
            arr[k++] = arr2[j++];
        }
    }

    while (i < l1)
    {
        arr[k++] = arr1[i++];
    }
    while (j < l2)
    {
        arr[k++] = arr2[j++];
    }
}
void mergesort(vector<int> &arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = s + (e - s) / 2;
    mergesort(arr, s, mid);
    mergesort(arr, mid + 1, e);

    merge(arr, s, e);
}
int main()
{
    vector<int> arr = {4, 2, 7, 1, 2};
    int s = 0, e = arr.size() - 1;
    printArr(arr);
    mergesort(arr, s, e);
    printArr(arr);
    return 0;
}