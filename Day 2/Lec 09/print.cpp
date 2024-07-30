#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void printArr(int arr[], int n)
{
    cout << "Here is array:";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void scanArr(int arr[], int n)
{
    cout << "Enter array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Array entered" << endl;
}
int main()
{
    int n;
    cout << "Enter size of array" << endl;
    cin >> n;
    int *arr = new int[n];
    scanArr(arr, n);
    printArr(arr, n);
    delete[] arr;
    return 0;
}