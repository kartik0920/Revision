#include <bits/stdc++.h>
#include <iostream>
using namespace std;
long long sumArr(int arr[], int n)
{
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += arr[i];
    }
    return ans;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << sumArr(arr, size) << endl;
    return 0;
}