#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool BS(vector<int> arr, int key)
{
    int s = 0, e = arr.size() - 1;
    int mid = s + (e - s) / 2;
    while (e >= s)
    {
        if (arr[mid] == key)
        {
            return 1;
        }
        else if (arr[mid] < key)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return 0;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int key = 1;
    if (BS(arr, key))
    {
        cout << "Present" << endl;
    }
    else
    {
        cout << "Absent" << endl;
    }
    return 0;
}