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
}
void swapAlter(int arr[], int n)
{
    int i = 0, j = 1;
    while (j < n)
    {
        swap(arr[i], arr[j]);
        i += 2;
        j += 2;
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    swapAlter(arr, size);
    printArr(arr, size);
    return 0;
}