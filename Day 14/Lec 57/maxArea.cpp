#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> nextSmall(vector<int> arr, int n)
{
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (s.top() != -1 && arr[s.top()] >= arr[i])
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<int> prevSmall(vector<int> arr, int n)
{
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);
    for (int i = 0; i < n; i++)
    {
        while (s.top() != -1 && arr[s.top()] >= arr[i])
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int areaHistogram(vector<int> arr)
{
    int n = arr.size();
    vector<int> next = nextSmall(arr, n);
    vector<int> prev = prevSmall(arr, n);
    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int l = arr[i];
        if (next[i] == -1)
        {
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;
        area = max(area, l * b);
    }
    return area;
}

int maxArea(vector<vector<int>> M)
{
    int area = areaHistogram(M[0]);
    for (int i = 1; i < M.size(); i++)
    {
        for (int j = 0; j < M[i].size(); j++)
        {
            if (M[i][j])
            {
                M[i][j] += M[i - 1][j];
            }
            else
            {
                M[i][j] = 0;
            }
        }
        area = max(area, areaHistogram(M[i]));
    }
    return area;
}
int main()
{
    vector<vector<int>> mat = {{0, 1, 1, 1},
                               {1, 1, 1, 1}};
    // vector<vector<int>> mat = {{0, 1, 1, 0},
    //                            {1, 1, 1, 1},
    //                            {1, 1, 1, 1},
    //                            {1, 1, 0, 0}};
    cout << maxArea(mat) << endl;
    return 0;
}