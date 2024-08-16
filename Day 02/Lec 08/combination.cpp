#include <bits/stdc++.h>
#include <iostream>
using namespace std;

long long fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * fact(n - 1);
}
long long combination(int n, int r)
{
    long long numerator = fact(n);
    long long denominator = fact(n - r) * fact(r);

    return numerator / denominator;
}
int main()
{
    cout << combination(4, 2) << endl;
    return 0;
}