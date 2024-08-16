#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool IsEven(int n)
{
    return n & 1 ? 0 : 1;
}
int main()
{
    int n = 3;
    if (IsEven(n))
    {
        cout << "Even" << endl;
    }
    else
    {
        cout << "Odd" << endl;
    }
    return 0;
}