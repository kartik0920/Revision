#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> solve(vector<int> arr)
{
    vector<int> ans(arr.size());
    stack<int> st;
    st.push(-1);
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (st.top() > arr[i])
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;
}
int main()
{
    vector<int> arr = {2, 1, 4, 3};
    vector<int> ans = solve(arr);
    for (auto i : ans)
    {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}