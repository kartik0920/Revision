#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    char ch;
    cout << "Enter the character:";
    cin >> ch;
    if (ch >= 'a' && ch <= 'z')
    {
        cout << "Lowercase" << endl;
    }
    else if (ch >= 'A' && ch <= 'Z')
    {
        cout << "Uppercase" << endl;
    }
    else
    {
        cout << "Special Character" << endl;
    }
    return 0;
}