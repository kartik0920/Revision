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
int unique(int arr[], int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}
int main()
{
    int arr[] = {1, 1, 2, 3, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << unique(arr, size) << endl;
    return 0;
}