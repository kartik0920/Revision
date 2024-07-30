#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void minmax(int arr[], int n)
{
    int min = INT_MAX, max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    cout << "min is " << min << endl;
    cout << "max is " << max << endl;
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    minmax(arr, size);
    return 0;
}