#include <bits/stdc++.h>
#include <iostream>
using namespace std;
string convert(int n)
{
    string ans = "";
    for (int i = n; n != 0; n = n >> 1)
    {
        if (n & 1)
        {
            ans.insert(0, "1");
        }
        else
        {
            ans.insert(0, "0");
        }
    }
    return ans;
}
int main()
{
    int n = 9;
    cout << convert(n) << endl;
    return 0;
}