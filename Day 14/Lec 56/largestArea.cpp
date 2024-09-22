#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void printArr(vector<int> arr)
{
    for (auto i : arr)
    {
        cout << i << ' ';
    }
    cout << endl;
}

vector<int> getNextSmall(vector<int> arr)
{
    vector<int> ans(arr.size());
    stack<int> st;
    st.push(-1);
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (st.top() != -1 && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}
vector<int> getPrevSmall(vector<int> arr)
{
    vector<int> ans(arr.size());
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < arr.size(); i++)
    {
        if (st.top() != -1 && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int largestArea(vector<int> arr)
{
    int n = arr.size();
    vector<int> next = getNextSmall(arr);
    vector<int> prev = getPrevSmall(arr);
    int ans = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        int l = arr[i];
        if (next[i] == -1)
        {
            arr[i] = n;
        }
        int b = next[i] - prev[i] - 1;
        ans = max(ans, l * b);
    }
    return ans;
}
int main()
{
    vector<int> arr = {2, 1, 5, 6, 2, 3};
    cout << largestArea(arr) << endl;
    return 0;
}