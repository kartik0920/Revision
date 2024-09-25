#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> solve(vector<int> arr, int k)
{
    vector<int> ans;
    int n = arr.size();
    deque<int> dq;
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
    }
    if (dq.empty())
    {
        ans.push_back(0);
    }
    else
    {
        ans.push_back(arr[dq.front()]);
    }

    for (int i = k; i < n; i++)
    {
        if (i - dq.front() >= k)
        {
            dq.pop_front();
        }
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }

        if (dq.empty())
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back(arr[dq.front()]);
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {12, -1, -7, 8, -15, 30, 18, 28};
    int k = 3;
    // vector<int> arr = {-8, 2, 3, -6, 10};
    // int k = 2;
    vector<int> ans = solve(arr, k);
    for (auto i : ans)
    {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}