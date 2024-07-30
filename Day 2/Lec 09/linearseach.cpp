#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool LS(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int arr[] = {4, 2, 4, 4, 3, 43, 1, 6, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 43;
    if (LS(arr, size, key))
    {
        cout << "Present" << endl;
    }
    else
    {
        cout << "Absent" << endl;
    }
    return 0;
}