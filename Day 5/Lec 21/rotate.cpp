#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void printArr(vector<int> arr)
{
    cout << "here is array:";
    for (auto i : arr)
    {
        cout << i << ' ';
    }
    cout << endl;
}
void rotate(vector<int> &arr, int key)
{
    vector<int> temp = arr;
    int s = arr.size();
    for (int i = 0; i < s; i++)
    {
        arr[(i + key) % s] = temp[i];
    }
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int k = 2;
    printArr(arr);
    rotate(arr, k);
    printArr(arr);
    return 0;
}