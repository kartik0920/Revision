#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    cout << "Q  back is " << q.back() << endl;
    cout << "Q front is " << q.front() << endl;
    q.pop();
    cout << "Q  back is " << q.back() << endl;
    cout << "Q front is " << q.front() << endl;
    if (q.empty())
    {
        cout << "Q is empty" << endl;
    }
    else
    {
        cout << "Q is not empty" << endl;
    }

    cout << q.size() << endl;
    return 0;
}