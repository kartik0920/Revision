#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void asccnt(int n)
{
    if (n == 0)
    {
        return;
    }
    asccnt(n - 1);
    cout << n << ' ';
}
void descnt(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << ' ';
    descnt(n - 1);
}
int main()
{
    int n;
    cout << "Enter n:";
    cin >> n;
    cout << "asc count : ";
    asccnt(n);
    cout << "\ndes count : ";
    descnt(n);
    return 0;
}