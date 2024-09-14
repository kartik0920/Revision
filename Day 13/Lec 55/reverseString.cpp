#include <bits/stdc++.h>
#include <iostream>
using namespace std;
string reverse(string str)
{
    stack<char> s;
    for (auto i : str)
    {
        s.push(i);
    }
    string ans = "";
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
int main()
{
    string str = "Kartik";
    cout << str << " " << reverse(str) << endl;
    return 0;
}