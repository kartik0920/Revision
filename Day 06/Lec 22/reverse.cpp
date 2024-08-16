#include <bits/stdc++.h>
#include <iostream>
using namespace std;
string reverse(string str)
{
    int s = 0, e = str.length() - 1;
    while (e >= s)
    {
        swap(str[s++], str[e--]);
    }
    return str;
}
int main()
{
    string str = "kartik";
    cout << str << ':' << reverse(str) << endl;
    return 0;
}