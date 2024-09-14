#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool check(char a, char b)
{
    if (a == '}' && b == '{' || a == ']' && b == '[' || a == ')' && b == '(')
    {
        return 1;
    }
    return 0;
}

bool isValid(string str)
{
    stack<char> S;
    for (int i = 0; i < str.length(); i++)
    {
        char a = str[i];
        if (a == '[' || a == '(' || a == '{')
        {
            S.push(a);
        }
        else
        {
            if (S.empty())
            {
                return 0;
            }
            if (check(a, S.top()))
            {
                S.pop();
            }
            else
            {
                return 0;
            }
        }
    }
    return S.empty();
}
int main()
{
    string str = "[{)}]";
    if (isValid(str))
    {
        cout << "Valid" << endl;
    }
    else
    {
        cout << "Invalid" << endl;
    }
    return 0;
}