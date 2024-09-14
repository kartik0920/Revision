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

void sortedInsert(stack<int> &S, int a)
{
    if (S.empty() || (!S.empty() && S.top() <= a))
    {
        S.push(a);
        return;
    }
    int x = S.top();
    S.pop();
    sortedInsert(S, a);
    S.push(x);
}

void sort(stack<int> &S)
{
    if (S.empty())
    {
        return;
    }
    int a = S.top();
    S.pop();
    sort(S);
    sortedInsert(S, a);
}
int main()
{
    stack<int> S;
    S.push(1);
    S.push(2);
    S.push(5);
    S.push(4);
    S.push(3);
    print(S);
    sort(S);
    print(S);
    return 0;
}