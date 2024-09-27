#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int solve(vector<int> arr, int k)
{
    int ans = 0;
    deque<int> maxi, mini;
    for (int i = 0; i < k; i++)
    {
        while (!maxi.empty() && arr[maxi.front()] <= arr[i])
        {
            maxi.pop_back();
        }
        while (!mini.empty() && arr[mini.front()] >= arr[i])
        {
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }
    ans += arr[maxi.front()] + arr[mini.front()];
    int n = arr.size();
    for (int i = k; i < n; i++)
    {
        if (!maxi.empty() && i - maxi.front() >= k)
        {
            maxi.pop_front();
        }
        if (!mini.empty() && i - mini.front() >= k)
        {
            mini.pop_front();
        }

        while (!maxi.empty() && arr[maxi.front()] <= arr[i])
        {
            maxi.pop_back();
        }
        while (!mini.empty() && arr[mini.front()] >= arr[i])
        {
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
        ans += arr[maxi.front()] + arr[mini.front()];
    }
    return ans;
}
int main()
{
    vector<int> arr = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << solve(arr, k) << endl;
    return 0;
}