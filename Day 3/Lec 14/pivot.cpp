#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int pivotIndex(vector<int> &nums)
{
    int size = nums.size();
    int s = 0, e = nums.size();
    int mid = s + (e - s) / 2;
    while (e > s)
    {
        if (nums[mid] >= nums[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    s = s % size;
    return s;
}
int main()
{
    vector<int> arr = {4, 5, 6, 1, 2};
    cout << arr[pivotIndex(arr)] << endl;
    return 0;
}