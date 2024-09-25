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

queue<int> reverse1(queue<int> q)
{
    stack<int> s;
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    return q;
}

void solve(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }
    int a = q.front();
    q.pop();
    solve(q);
    q.push(a);
}
queue<int> reverse2(queue<int> &q)
{
    queue<int> ans;
    solve(q);
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
    queue<int> r1 = reverse1(q);
    print(r1);
    queue<int> r2 = reverse2(q);
    print(r2);
    return 0;
}