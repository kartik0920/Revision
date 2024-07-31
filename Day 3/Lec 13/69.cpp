#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int mySqrt(int x)
{
    int ans = 0;
    int s = 1, e = x;
    int mid = s + (e - s) / 2;
    while (e >= s)
    {
        if (mid * mid == x)
        {
            return mid;
        }
        else if (mid * mid < x)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int main()
{
    int n = 6;
    cout << mySqrt(n) << endl;
    return 0;
}