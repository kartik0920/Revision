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
void quickSort(vector<int> &arr)
{
    int size = arr.size();
    for (int i = 1; i < size; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = temp;
    }
}
int main()
{
    vector<int> arr = {1, 4, 3, 2};
    printArr(arr);
    quickSort(arr);
    printArr(arr);

    return 0;
}