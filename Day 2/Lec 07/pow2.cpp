#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool isPow2(int n)
{
    /*
        int count = 0;
        while (n != 0)
        {
            if (n & 1)
            {
                count++;
                if (count > 1)
                {
                    return 0;
                }
            }
            n = n >> 1;
        }
        return 1;
        */

    // OR4

    return !(n & (n - 1));
}
int main()
{
    int n = 32;
    if (isPow2(n))
    {
        cout << "2 power!" << endl;
    }
    else
    {
        cout << "Not 2 power!" << endl;
    }
    return 0;
}