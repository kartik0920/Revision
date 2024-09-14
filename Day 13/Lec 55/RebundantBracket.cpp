#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool isRebundant(string str)
{
    stack<char> st;
    for (auto i : str)
    {
        if (i == '(' || i == '+' || i == '-' || i == '*' || i == '/')
        {
            st.push(i);
        }
        else
        {
            if (i == ')')
            {
                bool x = 1;
                while (st.top() != '(')
                {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        x = 0;
                    }
                    st.pop();
                }
                if (x)
                {
                    return 1;
                }
                st.pop();
            }
        }
    }
    return 0;
}
int main()
{
    string str = "(b-a)";
    if (isRebundant(str))
    {
        cout << "Rebundant" << endl;
    }
    else
    {
        cout << "Not" << endl;
    }
    return 0;
}