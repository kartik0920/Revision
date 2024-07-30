#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int reverse(int x)
{
    int ans = 0;
    for (int i = x; i != 0; i /= 10)
    {
        ans = ans * 10 + (i % 10);
    }
    return ans;
}
int main()
{
    int n;
    cout << "Enter n:";
    cin >> n;
    cout << n << ' ' << reverse(n) << endl;
    return 0;
}