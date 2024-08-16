#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool isRotated(vector<int> arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i - 1] > arr[i])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    vector<int> arr = {1, 1};
    if (isRotated(arr))
    {
        cout << "Sorted" << endl;
    }
    else
    {
        cout << "Not sorted" << endl;
    }
    return 0;
}