#include <bits/stdc++.h>
#include <iostream>
using namespace std;
long long pow(int a, int b)
{
    int ans = 1;
    for (int i = 0; i < b; i++)
    {
        ans *= a;
    }
    return ans;
}
int main()
{
    cout << pow(2, 3) << endl;
    return 0;
}