#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// check if array is sorted

int sum(vector<int> arr, int s)
{
    if (s >= arr.size())
    {
        return 0;
    }

    return arr[s] + sum(arr, s + 1);
}

int main()
{
    vector<int> arr = {1, 13, 23};
    int s = 0;
    cout << sum(arr, s) << endl;

    return 0;
}