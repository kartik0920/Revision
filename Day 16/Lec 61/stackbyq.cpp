#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Qstack
{
    queue<int> q;

public:
    bool empty()
    {
        return q.empty();
    }
    void push(int x)
    {
        q.push(x);
    }
    int peek()
    {
        if (q.empty())
        {
            cout << "Empty Stack" << endl;
            return -1;
        }
        return q.back();
    }

    void pop()
    {
        if (empty())
        {
            return;
        }
        int n = q.size() - 1, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int a = q.front();
            q.push(a);
            q.pop();
        }
        q.pop();
    }
};
int main()
{
    Qstack st;
    // cout << st.empty() << endl;
    st.push(12);
    st.push(13);
    st.push(14);
    // cout << st.peek() << endl;
    st.pop();

    cout << st.peek() << endl;

    return 0;
}