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
void reverseArr(int arr[], int size)
{
    int s = 0, e = size - 1;
    while (e >= s)
    {
        swap(arr[s++], arr[e--]);
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    printArr(arr, size);

    reverseArr(arr, size);
    printArr(arr, size);
    return 0;
}