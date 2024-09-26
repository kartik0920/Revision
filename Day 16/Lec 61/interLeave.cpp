#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void print(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << ' ';
        q.pop();
    }
    cout << endl;
}

void solve(queue<int> &q)
{
    queue<int> q1, q2;
    int cnt = 1;
    int size = q.size();
    while (!q.empty())
    {
        if (cnt <= size / 2)
        {
            q1.push(q.front());
        }
        else
        {
            q2.push(q.front());
        }
        cnt++;
        q.pop();
    }
    cnt = 0;
    while (!q1.empty() || !q2.empty())
    {
        if (!q1.empty())
        {
            int a = q1.front();
            q.push(a);
            q1.pop();
        }
        if (!q2.empty())
        {
            int b = q2.front();
            q.push(b);
            q2.pop();
        }

        cnt++;
    }
}
int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    print(q);
    solve(q);
    print(q);
    return 0;
}