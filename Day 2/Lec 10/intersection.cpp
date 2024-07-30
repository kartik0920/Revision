#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void printArr(vector<int> arr)
{
    cout << "Here is array:";
    for (auto i : arr)
    {
        cout << i << ' ';
    }
    cout << endl;
}
vector<int> duplicate(vector<int> arr1, vector<int> arr2)
{
    vector<int> ans;
    unordered_map<int, bool> mapping;
    for (auto i : arr1)
    {
        mapping[i] = 1;
    }
    for (auto i : arr2)
    {
        if (mapping[i])
        {
            ans.push_back(i);
        }
    }
    return ans;
}
int main()
{
    vector<int> arr1 = {1, 4, 3, 2, 2};
    vector<int> arr2 = {1, 4, 2};

    vector<int> dupliArr = duplicate(arr1, arr2);
    printArr(dupliArr);
    return 0;
}