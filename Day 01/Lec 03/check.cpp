#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void check(int a)
{
    if (a > 0)
    {
        cout << "Positive" << endl;
    }
    else if (a == 0)
    {
        cout << "Zero" << endl;
    }
    else
    {
        cout << "Negative" << endl;
    }
}
int main()
{
    int a;
    cout << "Enter a:";

    cin >> a;

    check(a);
    return 0;
}