#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void printArr(int arr[], int n)
{
    cout << "Here is array:";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}
void merge(int arr1[], int arr2[], int *ans, int n, int m)
{
    int i = 0, j = 0;
    int k = 0;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            ans[k++] = arr1[i++];
        }
        else
        {
            ans[k++] = arr2[j++];
        }
    }
    while (i < n)
    {
        ans[k++] = arr1[i++];
    }

    while (j < m)
    {
        ans[k++] = arr2[j++];
    }
}
int main()
{
    int arr1[] = {1, 3, 5, 7};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {2, 4, 6};
    int m = sizeof(arr2) / sizeof(arr2[0]);

    printArr(arr1, n);
    printArr(arr2, m);

    int arr3[m + n];
    merge(arr1, arr2, arr3, n, m);
    printArr(arr3, m + n);

    return 0;
}