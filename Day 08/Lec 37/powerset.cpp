#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void printArr(vector<int> arr)
{
    for (auto i : arr)
    {
        cout << i << ' ';
    }
}

void printArr(vector<vector<int>> arr)
{
    for (auto i : arr)
    {
        printArr(i);
        cout << endl;
    }
}

void solve(vector<int> arr, vector<int> temp, vector<vector<int>> &ans, int i)
{
    if (i == arr.size())
    {
        ans.push_back(temp);
        return;
    }
    // include
    temp.push_back(arr[i]);
    solve(arr, temp, ans, i + 1);
    temp.pop_back();
    solve(arr, temp, ans, i + 1);
}

vector<vector<int>> getPowerset(vector<int> arr)
{
    vector<int> temp;
    vector<vector<int>> ans;
    solve(arr, temp, ans, 0);
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3};
    int s = 0, e = arr.size() - 1;
    printArr(arr);
    cout << endl;
    cout << "Here is powerset" << endl;
    vector<vector<int>> ans = getPowerset(arr);
    printArr(ans);

    return 0;
}