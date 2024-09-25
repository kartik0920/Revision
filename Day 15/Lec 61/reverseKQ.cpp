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

queue<int> reverseK(queue<int> q, int k)
{
    stack<int> s;
    for (int i = 0; i < k; i++)
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    int t = q.size() - k - 1;
    for (; t >= 0; t--)
    {
        int a = q.front();
        q.pop();
        q.push(a);
    }
    return q;
}
int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    print(q);
    int k = 2;
    queue<int> r = reverseK(q, k);
    print(r);
    return 0;
}