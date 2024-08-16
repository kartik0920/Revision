#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool LS(vector<int> arr, int s, int key)
{
    if (s == arr.size())
    {
        return 0;
    }
    if (arr[s] == key)
    {
        return 1;
    }

    return LS(arr, s + 1, key);
}
int main()
{
    vector<int> arr = {5, 12, 3, 5, 6};
    int s = 0;
    int key = 12;
    if (LS(arr, s, key))
    {
        cout << "Present" << endl;
    }
    else
    {
        cout << "Absent" << endl;
    }
    return 0;
}