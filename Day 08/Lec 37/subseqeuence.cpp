#include <bits/stdc++.h>
#include <iostream>
using namespace std;

template <typename T>

void printArr(vector<T> arr)
{
    for (auto i : arr)
    {
        cout << i << ' ';
    }
    cout << endl;
}

void solve(string str, vector<string> &ans, int i, string temp)
{
    if (i == str.length())
    {
        ans.push_back(temp);
        return;
    }

    // include
    solve(str, ans, i + 1, temp + str[i]);
    solve(str, ans, i + 1, temp);
}

vector<string> getSub(string str)
{
    vector<string> ans;
    int i = 0;
    string temp;
    solve(str, ans, i, temp);
    return ans;
}

int main()
{
    string str = "abc";
    vector<string> subsequence = getSub(str);
    printArr(subsequence);
    return 0;
}