#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void caluculate(int a, int b, char ch)
{
    switch (ch)
    {
    case '+':
        cout << a << ch << b << '=' << a + b << endl;
        break;
    case '-':
        cout << a << ch << b << '=' << a - b << endl;
        break;
    case '*':
        cout << a << ch << b << '=' << a * b << endl;
        break;
    case '/':
        cout << a << ch << b << '=' << a / b << endl;
        break;
    case '%':
        cout << a << ch << b << '=' << a % b << endl;
        break;

    default:
        cout << "Enter correct operand" << endl;
        break;
    }
}
int main()
{
    cout << "------------------------- Here is Calculator-------------------------" << endl;
    do
    {
        int a, b;
        cout << "Enter a:";
        cin >> a;
        cout << "Enter b:";
        cin >> b;
        char ch;
        cout << "Enter Char:";
        cin >> ch;
        caluculate(a, b, ch);
        cout << "Do you want to recalculate:" << endl;
        cout << "1 for Yes\n";
        cout << "0 for No\n";
        bool check;
        cin >> check;
        if (!check)
        {
            break;
        }

    } while (true);
    cout << "------------Code Runned SuccesFully-----------------";
    return 0;
}