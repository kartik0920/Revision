#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int bitwiseComplement(int n)
{
    int notn = ~n;
    int var = 0;
    while (n != 0)
    {
        var = var << 1 | 1;
        n = n >> 1;
    }
    return notn & var;
}
int main()
{
    int n;
    cout << "Enter n:";
    cin >> n;
    cout << bitwiseComplement(n) << endl;
    return 0;
}