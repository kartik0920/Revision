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

void insertBottom(stack<int> &S, int x)
{
    if (S.empty())
    {
        S.push(x);
        return;
    }
    int a = S.top();
    S.pop();
    insertBottom(S, x);
    S.push(a);
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
    insertBottom(S, 0);
    print(S);
    return 0;
}