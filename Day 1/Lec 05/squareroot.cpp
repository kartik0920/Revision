#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int sqrt(int n)
{
    // int ans = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     if (i * i <= n)
    //     {
    //         ans = i;
    //     }
    //     else
    //     {
    //         break;
    //     }
    // }
    // return ans;

    int ans = 0;
    int s = 1, e = n;

    int mid = s + (e - s) / 2;
    while (e >= s)
    {
        int sqr = mid * mid;
        if (sqr == n)
        {
            return mid;
        }
        else if (sqr < n)
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
    int n;
    cout << "Enter n:";
    cin >> n;
    cout << sqrt(2) << endl;
    cout << sqrt(3) << endl;
    cout << sqrt(4) << endl;
    return 0;
}