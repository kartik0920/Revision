#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    stack<int> s;
    s.push(23);
    cout << s.top() << endl;
    s.pop();
    cout << s.empty() << endl;
    cout << s.size() << endl;
    return 0;
}