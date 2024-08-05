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

void sort(vector<int> &arr, int s, int e)
{
    if (e < 0)
    {
        return;
    }
    for (int i = 1; i <= e; i++)
    {
        if (arr[i - 1] >= arr[i])
        {
            swap(arr[i - 1], arr[i]);
        }
    }

    sort(arr, s, e - 1);
}
int main()
{
    vector<int> arr = {5, 2, 5, 7, 12};
    int s = 0, e = arr.size() - 1;
    printArr(arr);
    sort(arr, s, e);
    printArr(arr);

    return 0;
}