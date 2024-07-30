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
int duplicate(int arr[], int n)
{
    unordered_map<int, bool> mapping;
    for (int i = 0; i < n; i++)
    {
        if (mapping[arr[i]])
        {
            return arr[i];
        }
        mapping[arr[i]] = 1;
    }
    return -1;
}
int main()
{
    int arr[] = {1, 4, 3, 2, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << duplicate(arr, size) << endl;
    return 0;
}