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
void reverse(vector<int> &arr, int s)
{
    int e = arr.size() - 1;
    while (e >= s)
    {
        swap(arr[s++], arr[e--]);
    }
}
int main()
{
    vector<int> arr = {1, 3, 4, 5, 6};
    printArr(arr);
    reverse(arr, 1);
    printArr(arr);
    return 0;
}