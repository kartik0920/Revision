#include <bits/stdc++.h>
#include <iostream>
using namespace std;
long long Fibo(int n)
{
    // long long ans = 0;
    // if (n <= 0)
    // {
    //     return 0;
    // }
    // if (n == 1)
    // {
    //     return 1;
    // }
    // int first = 0, second = 1;
    // for (int i = 2; i < n; i++)
    // {
    //     ans = first + second;
    //     first = second;
    //     second = ans;
    // }
    // return ans;
    if (n <= 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    return Fibo(n - 2) + Fibo(n - 1);
}
int main()
{
    int n;
    cout << "Enter n:";
    cin >> n;
    cout << Fibo(n) << endl;
    return 0;
}