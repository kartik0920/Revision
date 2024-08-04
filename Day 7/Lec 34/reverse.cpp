#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void reverse(string &str, int s, int e)
{
    if (s >= e)
    {

        return;
    }
    reverse(str, s + 1, e - 1);
    swap(str[s], str[e]);
}
int main()
{
    string str = "kit-kat";
    int s = 0, e = str.length() - 1;
    cout << str << " ";
    reverse(str, s, e);
    cout << str << endl;
    return 0;
}