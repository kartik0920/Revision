#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool isPow2(int n)
{
    return !(n & (n - 1));
}
bool isValid(int a, int b)
{
    if (a > b)
    {
        return 0;
    }
    int diff = b - a;
    return isPow2(diff);
}

int getLis(int N, vector<int> A)
{
    if (N == 1)
    {
        return 1;
    }
    int max = INT_MIN;
    int len = 1;
    for (int i = 1; i < A.size(); i++)
    {

        if (isValid(A[i - 1], A[i]))
        {
            len++;
            if (len > max)
            {
                max = len;
            }
            cout << A[i - 1] << A[i] << endl;
        }
        else
        {
            len = 1;
        }
    }
    return max;
}
int main()

{
    vector<int> A = {1,
                     2};
    int N = 1;
    cout << getLis(N, A) << endl;
    return 0;
}