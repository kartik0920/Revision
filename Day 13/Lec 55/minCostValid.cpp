// minimum cost to make string valid
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int minCost(string str)
{
    if (str.length() & 1)
    {
        return -1;
    }
    stack<char> s;
    for (auto i : str)
    {
        if (i == '{')
        {
            s.push(i);
        }
        else
        {
            if (!s.empty() && s.top() == '{')
            {
                s.pop();
            }
            else
            {
                s.push(i);
            }
        }
    }
    int a = 0, b = 0;
    while (!s.empty())
    {
        if (s.top() == '{')
        {
            a++;
        }
        else
        {
            b++;
        }
        s.pop();
    }
    int ans = (a + 1) / 2 + (b + 1) / 2;
    return ans;
}
int main()
{
    string str = "}{";
    cout << minCost(str) << endl;
    return 0;
}