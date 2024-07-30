#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int hammingWeight(int n)
{
    int ans = 0;
    for (int i = n; i != 0; i = i >> 1)
    {
        if (i & 1)
        {
            ans++;
        }
    }
    return ans;
}
int main()
{
    int n;
    cout << "Enter n:";
    cin >> n;
    cout << hammingWeight(n) << endl;
    return 0;
}