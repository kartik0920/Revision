#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool BS(vector<int> arr, int s, int e, int key)
{
    if (s > e)
    {
        return 0;
    }
    int mid = s + (e - s) / 2;
    if (arr[mid] == key)
    {
        return 1;
    }

    else if (arr[mid] > key)
    {
        return BS(arr, s, mid - 1, key);
    }
    else
    {
        return BS(arr, mid + 1, e, key);
    }
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int s = 0, e = arr.size() - 1;
    int key = 1;
    if (BS(arr, s, e, key))
    {
        cout << "Present" << endl;
    }
    else
    {
        cout << "Absent" << endl;
    }
    return 0;
}