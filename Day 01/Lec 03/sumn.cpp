#include <bits/stdc++.h>
#include <iostream>
using namespace std;
long long sum(int n)
{
    // long long ans = 0;
    // for (int i = 0; i <= n; i++)
    // {
    //     ans += i;
    // }
    // return ans;

    // or
    return (n / 2) * (n + 1);
}
int main()
{
    int n;
    cout << "Enter n:";
    cin >> n;
    cout << sum(n) << endl;
    return 0;
}