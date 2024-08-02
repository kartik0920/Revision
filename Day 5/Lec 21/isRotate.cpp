#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool isRotated(vector<int> arr)
{
    int cnt = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i - 1] > arr[i])
        {
            cnt++;
        }
    }
    if (arr[0] <= arr[arr.size() - 1])
    {
        cnt++;
    }

    return cnt == 1 ? 1 : 0;
}
int main()
{
    vector<int> arr = {4, 5, 6, 1, 2};
    if (isRotated(arr))
    {
        cout << "Rotated" << endl;
    }
    else
    {
        cout << "Not Rotated" << endl;
    }
    return 0;
}