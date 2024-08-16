#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int convert(string binary)
{
    int ans = 0;
    for (int i = binary.length() - 1, j = 0; i >= 0; i--, j++)
    {
        if (binary[i] == '1')
        {
            ans = ans + pow(2, j);
        }
    }
    return ans;
}
int main()
{
    string binary = "1011011";
    cout << convert(binary) << endl;
    return 0;
}