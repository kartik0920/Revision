#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int pow(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a;
    }

    int ans = pow(a * a, b / 2);
    if (b & 1)
    {
        ans *= a;
    }
    return ans;
}
int main()
{
    int a, b;
    cout << "Enter a:";
    cin >> a;
    cout << "Enter b:";
    cin >> b;

    cout << pow(a, b) << endl;
    return 0;
}