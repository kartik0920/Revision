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
            for (int k = j + 1; k < arr.size(); k++)
            {
                if (arr[i] + arr[j] + arr[k] == sum)
                {
                    cout << '{' << arr[i] << ',' << arr[j] << ',' << arr[k] << '}' << endl;
                }
            }
        }
    }
}

int main()
{
    vector<int> arr1 = {1, 4, 3, 2, 2};
    int sum = 8;
    tripletsum(arr1, sum);
    return 0;
}