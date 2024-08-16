#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool isPrime(int n)
{
    if (n <= 1)
    {
        return 0;
    }
    unordered_map<int, bool> mapping;

    for (int i = 2; i < n; i++)
    {
        if (!mapping[i])
        {
            mapping[i] = 1;
            for (int j = i + i; j <= n; j += i)
            {
                mapping[j] = 1;
            }
        }
    }

    return !mapping[n];
}
int main()
{
    if (isPrime(123))
    {
        cout << "prime";
    }
    else
    {
        cout << "Not";
    }

    return 0;
}