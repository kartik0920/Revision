#include <bits/stdc++.h>
#include <iostream>
using namespace std;

long long Fact(int n)
{
    /*  if (n < 0)
      {
          cout << "Enter correct number " << endl;
          return 0;
      }
      int ans = 1;
      for (int i = 1; i <= n; i++)
      {
          ans *= i;
      }
      return ans;*/

    //   OR

    if (n == 0)
    {
        return 1;
    }
    return Fact(n - 1) * n;
}
int main()
{
    int n = 5;
    cout << n << "! = " << Fact(n);

    return 0;
}