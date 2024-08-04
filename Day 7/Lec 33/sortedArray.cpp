#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// check if array is sorted

bool isSort(vector<int> arr, int s, int e)
{
    if (s >= e)
    {
        return 1;
    }
    if (arr[s] > arr[s + 1])
    {
        return 0;
    }

    return isSort(arr, s + 1, e);
}

int main()
{
    vector<int> arr = {13, 13, 45};
    int s = 0, e = arr.size() - 1;
    if (isSort(arr, s, e))
    {
        cout << "Sorted" << endl;
    }
    else
    {
        cout << "Not" << endl;
    }
    return 0;
}