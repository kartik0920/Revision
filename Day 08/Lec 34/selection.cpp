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
    if (s == e)
    {
        return;
    }
    int min = s;
    int i = s;
    for (; i <= e; i++)
    {
        if (arr[i] < arr[min])
        {
            min = i;
        }
    }
    swap(arr[s], arr[min]);
    sort(arr, s + 1, e);
}
int main()
{
    vector<int> arr = {4, 2, 1, 3};
    int s = 0, e = arr.size() - 1;
    printArr(arr);
    sort(arr, s, e);
    printArr(arr);

    return 0;
}