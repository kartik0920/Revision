#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int solve(vector<pair<int, int>> arr, int n)
{
    int bal = 0;
    int front = 0, rear = 0;
    bool check = 0;
    for (int i = 0; i <= 2 * n; i++)
    {

        if (check && front == rear)
        {
            return front;
        }
        int x = bal + arr[i % n].first - arr[i % n].second;
        if (x >= 0)
        {
            bal = x;
            rear = (rear + 1) % n;
            check = 1;
        }
        else
        {
            front = (rear + 1) % n;
            rear = (rear + 1) % n;
            bal = 0;
            check = 0;
        }
    }
    return -1;
}
int main()
{
    vector<pair<int, int>> arr = {
        {6, 5},
        {7, 6},
        {4, 7},
        {10, 8},
        {6, 6},
        {5, 4}};
    int n = arr.size();
    cout << solve(arr, n) << endl;
    return 0;
}