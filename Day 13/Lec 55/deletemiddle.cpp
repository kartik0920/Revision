#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void print(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << ' ';
        s.pop();
    }
    cout << endl;
}

void solve(stack<int> &S, int n, int count)

{
    if ((n / 2) == count)
    {
        S.pop();
        return;
    }
    int a = S.top();
    S.pop();
    solve(S, n, count + 1);
    S.push(a);
}

void deleteMiddle(stack<int> &S, int n)
{
    int count = 0;
    solve(S, n, count);
}

int main()
{
    stack<int> S;
    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    S.push(5);
    print(S);
    deleteMiddle(S, S.size());
    print(S);
    return 0;
}