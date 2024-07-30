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

void tripletsum(vector<int> arr, int sum)
{
    for (auto i = 0; i < arr.size(); i++)
    {
        for (auto j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] + arr[j] == sum)
            {
                cout << '{' << arr[i] << ',' << arr[j] << '}' << endl;
            }
        }
    }
}

int main()
{
    vector<int> arr1 = {1, 4, 3, 2, 2};
    int sum = 5;
    tripletsum(arr1, sum);
    return 0;
}