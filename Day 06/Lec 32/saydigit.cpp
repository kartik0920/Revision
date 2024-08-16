#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void saydigit(int n, vector<string> dict)
{
    if (n == 0)
    {
        return;
    }
    saydigit(n / 10, dict);
    cout << dict[n % 10] << " ";
}
int main()
{
    int n = 271;
    vector<string> dict = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    saydigit(n, dict);

    return 0;
}