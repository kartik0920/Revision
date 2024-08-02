
#include <iostream>
#include <vector>
using namespace std;

void printArr(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void movezero(vector<int> &arr)
{
    int i = 0, nz = 0;
    while (i < arr.size())
    {
        if (arr[i] != 0)
        {
            swap(arr[nz], arr[i]);
            nz++;
        }
        i++;
    }
}
int main()
{
    vector<int> arr = {2, 4, 1, 4, 0};
    movezero(arr);
    printArr(arr);
    return 0;
}
