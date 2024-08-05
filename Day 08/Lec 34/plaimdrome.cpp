#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool checkpali(string str, int s, int e)
{
    if (s == e)
    {
        return 1;
    }
    if (str[s] != str[e])
    {
        return 0;
    }
    else
    {
        return checkpali(str, s + 1, e - 1);
    }
}
int main()
{
    string str = "mom";
    int s = 0, e = str.length() - 1;
    if (checkpali(str, s, e))
    {
        cout << "Palimdrome" << endl;
    }
    else
    {
        cout << "not" << endl;
    }
    return 0;
}