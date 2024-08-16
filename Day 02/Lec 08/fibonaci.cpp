#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void printFibo(int n)
{

    if (n <= 0)
    {

        return;
    }
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    int first = 0, second = 1;
    cout << first << ' ' << second << ' ';
    for (int i = 2; i < n; i++)
    {
        int third = first + second;
        cout << third << ' ';
        first = second;
        second = third;
    }
}
int main()
{
    int n = 5;
    printFibo(n);
    return 0;
}