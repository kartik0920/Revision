#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void printArr(vector<int> arr)
{
    cout << "This is array:";
    for (auto i : arr)
    {
        cout << i << ' ';
    }
    cout << endl;
}
void sort(vector<int> &arr)
{
    int size = arr.size();
    for (int i = 1; i < size - 1; i++)
    {
        bool check = 1;
        for (int j = 0; j < size - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                check = 0;
                swap(arr[j], arr[j + 1]);
            }
        }
        if (check)
        {
            break;
        }
    }
}
int main()
{
    vector<int> arr = {1, 2, 3, 4};
    printArr(arr);
    sort(arr);
    printArr(arr);

    return 0;
}