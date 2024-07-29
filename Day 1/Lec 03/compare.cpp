#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void comapare(int a, int b)
{
    if (a > b)
    {
        cout << "a is bigger" << endl;
    }
    else if (a == b)
    {
        cout << "both are equal" << endl;
    }
    else
    {
        cout << "b is bigger" << endl;
    }
}
int main()
{
    int a = 0, b = 0;
    cout << "Enter a:";
    cin >> a;
    cout << "Enter b:";
    cin >> b;
    comapare(a, b);
    return 0;
}