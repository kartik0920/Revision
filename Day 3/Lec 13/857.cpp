#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int peakIndexInMountainArray(vector<int> &arr)
{
    int ans = -1;
    int s = 0, e = arr.size() - 1;
    int mid = s + (e - s) / 2;
    while (e >= s)
    {
        if (s == e)
        {
            return arr[s];
        }
        else if (arr[mid] > arr[mid + 1])
        {
            e = mid;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int main()
{
    vector<int> arr = {0, 10, 5, 2};
    cout << peakIndexInMountainArray(arr) << endl;
    return 0;
}