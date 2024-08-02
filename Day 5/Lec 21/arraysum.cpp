// here we add 2 number represnted by array
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void printArr(vector<int> arr)
{
    cout << "here is array: ";
    for (auto i : arr)
    {
        cout << i;
    }
    cout << endl;
}

vector<int> sum(vector<int> arr1, vector<int> arr2)
{
    vector<int> ans;
    int m = arr1.size();
    int n = arr2.size();
    int carry = 0;
    int i = m - 1, j = n - 1;
    while (i >= 0 && j >= 0)
    {
        int n1 = arr1[i--];
        int n2 = arr2[j--];
        int sum = n1 + n2 + carry;
        ans.insert(ans.begin(), sum % 10);
        carry = sum / 10;
    }

    while (i >= 0)
    {
        int n1 = arr1[i--];
        int sum = n1 + carry;
        ans.insert(ans.begin(), sum % 10);
        carry = sum / 10;
    }
    while (j >= 0)
    {
        int n1 = arr2[j--];
        int sum = n1 + carry;
        ans.insert(ans.begin(), sum % 10);
        carry = sum / 10;
    }

    while (carry != 0)
    {
        ans.insert(ans.begin(), carry % 10);
        carry = carry / 10;
    }
    return ans;
}

int main()
{
    vector<int> arr1 = {1, 2, 3};
    vector<int> arr2 = {9, 9, 9, 9, 9};
    vector<int> sumof12 = sum(arr1, arr2);
    printArr(sumof12);
    return 0;
}