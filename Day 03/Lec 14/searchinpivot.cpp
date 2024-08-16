#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int getpivot(vector<int> nums)
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
    return s;
}
bool BS(vector<int> arr, int s, int e, int k)
{
    int mid = s + (e - s) / 2;
    while (e >= s)
    {
        if (arr[mid] == k)
        {
            return 1;
        }
        else if (arr[mid] < k)
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
bool search(vector<int> &arr, int key)
{
    int pivot = getpivot(arr);

    if (pivot == key)
    {
        return pivot - 1;
    }
    else if (key >= arr[0])
    {
        return BS(arr, 0, pivot - 1, key);
    }
    else
    {
        return BS(arr, pivot, arr.size() - 1, key);
    }
}
int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int key = 4;
    if (search(arr, key))
    {
        cout << "Present!" << endl;
    }
    else
    {
        cout << "Absent!" << endl;
    }
    return 0;
}