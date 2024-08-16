#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void printn(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << i << ' ';
    }
    cout << endl;
}
int main()
{
    int n;
    cout << "Enter n:";
    cin >> n;
    printn(n);
    return 0;
}