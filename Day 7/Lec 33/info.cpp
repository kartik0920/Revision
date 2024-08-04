#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int solve(int N, string x, int Q, int P, vector<vector<int>> matrix)
{
    int km = pow(10, 9) + 7;
    int ans = 1;
    for (auto i : matrix)
    {
        if (i[0] == 1)
        {
            x[i[2]] = i[1];
        }
        else if (i[0] == 2)
        {
            int max = INT_MIN;
            int len = 0;
            int s = i[1] - 1;
            int e = i[2] - 1;
            while (s <= e)
            {
                if (x[s] != x[s + 1])
                {

                    len++;
                    if (len > max)
                    {
                        max = len;
                    }
                }
                else
                {
                    len = 0;
                }
                s++;
            }
            ans = (ans * (max)) % km;
        }
        else
        {
            cout << 1;
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> mat = {
        {2, 2, 3},
        {2, 1, 3}};
    int N = 3;
    string x = "169";
    int Q = 2;
    int p = 3;

    cout << solve(N, x, Q, p, mat) << endl;
    return 0;
}