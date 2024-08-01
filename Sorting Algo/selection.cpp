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
    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }
}
int main()
{
    vector<int> arr = {2, 2, 3, 1};
    printArr(arr);
    sort(arr);
    printArr(arr);

    return 0;
}