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

void sort(vector<int> &arr, int size)
{
    if (size <= 1)
    {
        return;
    }
    sort(arr, size - 1);
    int temp = arr[size - 1];
    int i = size - 2;
    for (; i >= 0 && arr[i] > temp; i--)
    {

        arr[i + 1] = arr[i];
    }
    arr[i + 1] = temp;
}
int main()
{
    vector<int> arr = {4, 2, 1, 3};
    int s = 0, e = arr.size() - 1;
    printArr(arr);
    sort(arr, arr.size());
    printArr(arr);

    return 0;
}