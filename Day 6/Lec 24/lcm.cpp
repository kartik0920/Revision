#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int getGcd(int a, int b)
{
    if (a == b)
    {
        return a;
    }
    if (a == 1 || b == 1)
    {
        return 1;
    }
    return a > b ? getGcd(a - b, b) : getGcd(a, b - a);
}

int lcm(int a, int b)
{
    int gcd = getGcd(a, b);
    return (a * b) / gcd;
}
int main()
{
    int a, b;
    cout << "Enter a:";
    cin >> a;
    cout << "Enter b:";
    cin >> b;

    cout << lcm(a, b) << endl;
    return 0;
}