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

void insertBottom(stack<int> &S, int a)
{
    if (S.empty())
    {
        S.push(a);
        return;
    }
    int x = S.top();
    S.pop();
    insertBottom(S, a);
    S.push(x);
}

void reverse(stack<int> &S)
{
    if (S.empty())
    {
        return;
    }
    int a = S.top();
    S.pop();
    reverse(S);
    insertBottom(S, a);
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
    reverse(S);
    print(S);
    return 0;
}