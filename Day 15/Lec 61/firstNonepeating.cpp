#include <bits/stdc++.h>
#include <iostream>
using namespace std;

string solve(string str)
{
    string ans;
    unordered_map<char, bool> mapping;
    queue<int> q;
    for (auto i : str)
    {
        if (!mapping[i])
        {
            q.push(i);
        }

        while (!q.empty())
        {
            if (!mapping[i])
            {
                ans.push_back(q.front());
                break;
            }
            q.pop();
        }
        if (q.empty())
        {
            ans.push_back('$');
        }
        mapping[i] = 1;
    }
    return ans;
}

int main()
{
    string str = "aac";
    cout << solve(str) << endl;
    return 0;
}