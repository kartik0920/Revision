#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int firstOcc(vector<int> arr, int key)
{
    int ans = -1;
    int s = 0, e = arr.size() - 1;
    int mid = s + (e - s) / 2;
    while (e >= s)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            e = mid - 1;
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
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 2, 2, 5, 6};
    int key = 21;
    cout << firstOcc(arr, key) << endl;
    return 0;
}