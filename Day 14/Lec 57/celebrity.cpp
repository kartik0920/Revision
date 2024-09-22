#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int solve1(vector<vector<int>> M, int n)
{
    // stack<int> s;
    for (int i = 0; i < n; i++)
    {
        int Rcnt = 0, cCnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (M[i][j] == 0)
            {
                Rcnt++;
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (M[j][i] == 1)
            {
                cCnt++;
            }
        }
        if (Rcnt == n && cCnt == n - 1)
        {
            return i;
        }
    }
    return -1;
}

int solve2(vector<vector<int>> M, int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    while (s.size() != 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if (M[a][b])
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }
    int x = s.top();
    bool rCheck = 0, cCheck = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[x][i])
        {
            return -1;
        }
        if (!M[i][x] && i != x)
        {
            return -1;
        }
    }
    return x;
}
int main()
{
    vector<vector<int>> M = {{0, 1, 0},
                             {0, 0, 0},
                             {0, 1, 0}};
    // vector<vector<int>> M = {{0, 1},
    //                          {1, 0}};
    int n = M.size();
    cout << solve1(M, n) << endl;
    cout << solve2(M, n) << endl;
    return 0;
}