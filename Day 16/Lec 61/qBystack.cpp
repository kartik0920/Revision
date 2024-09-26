#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Stqueue
{
    stack<int> st;

public:
    bool empty()
    {
        return st.empty();
    }
    void push(int x)
    {
    }
    int peek()
    {
    }

    void pop()
    {
    }
};
int main()
{
    Stqueue q;
    cout << q.empty() << endl;
    q.push(12);
    q.push(13);
    q.push(14);
    cout << q.peek() << endl;

    return 0;
}