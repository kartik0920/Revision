#include <bits/stdc++.h>
#include <iostream>
using namespace std;

char islower(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        return ch - 'A' + 'a';
    }
    return ch;
}
bool isPali(string str)
{

    string temp = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {

            continue;
        }
        if (str[i] >= 'A' && str[i] <= 'z')
            temp = temp + str[i];
    }
    int s = 0, e = temp.length() - 1;
    while (e >= s)
    {

        if (islower(temp[s++]) != islower(temp[e--]))
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    string str = "A man, a plan, a canal: Panama";
    if (isPali(str))
    {
        cout << "Palimddrome" << endl;
    }
    else
    {
        cout << "Not" << endl;
    }
    return 0;
}