#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void pattern1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void pattern2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << j + 1 << ' ';
        }
        cout << endl;
    }
}
int main()
{

    int n;
    cout << "Enter n:" << endl;
    cin >> n;
    pattern1(n);
    pattern2(n);
    return 0;
}