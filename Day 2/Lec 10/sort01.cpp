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

void sort01(vector<int> &arr)
{
    int zerocnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            zerocnt++;
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (zerocnt != 0)
        {
            arr[i] = 0;
            zerocnt--;
        }
        else
        {
            arr[i] = 1;
        }
    }
}
int main()
{
    vector<int> arr = {0, 1, 0, 1};
    sort01(arr);
    printArr(arr);
    return 0;
}