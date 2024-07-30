#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int subtractProductAndSum(int n)
{
    long long product = 1;
    for (int i = n; i != 0; i /= 10)
    {
        product *= (i % 10);
    }
    long long sum = 0;
    for (int i = n; i != 0; i /= 10)
    {
        sum += (i % 10);
    }
    return product - sum;
}
int main()
{
    int n;
    cout << "Enter n:";
    cin >> n;
    cout << subtractProductAndSum(n) << endl;
    return 0;
}