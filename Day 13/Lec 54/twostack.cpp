#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Stack
{
public:
    int *arr;
    int size;
    int top1, top2;
    Stack(int d)
    {
        this->size = d;
        this->arr = new int[d];
        top1 = -1;
        top2 = d;
    }

    void push1(int x)
    {
        if (top2 - top1 - 1 >= 1)
        {
            top1++;
            arr[top1] = x;
        }
        else
        {
            cout << "OVERFLOW" << endl;
        }
    }
    void push2(int x)
    {
        if (top2 - top1 - 1 >= 1)
        {
            top2--;
            arr[top2] = x;
        }
        else
        {
            cout << "OVERFLOW" << endl;
        }
    }

    int peek1()
    {
        if (top1 == -1)
        {
            cout << "EMPTY" << endl;
            return -1;
        }
        return arr[top1];
    }
    int peek2()
    {
        if (top2 == size)
        {
            cout << "EMPTY" << endl;
            return -1;
        }
        return arr[top2];
    }

    bool isEmpty1()
    {
        return top1 == -1 ? 1 : 0;
    }

    bool isEmpty2()
    {
        return top2 == size ? 1 : 0;
    }

    void pop1()
    {
        if (top1 != -1)
        {
            top1--;
        }
        else
        {
            cout << "UNDERFLOWN" << endl;
        }
    }

    void pop2()
    {
        if (top2 != size)
        {
            top2++;
        }
        else
        {
            cout << "UNDERFLOW" << endl;
        }
    }
};
int main()
{
    Stack s(3);
    s.push1(1);
    s.push1(2);
    s.push2(-1);
    cout << s.peek1() << ' ' << s.peek2() << endl;

    s.pop2();
    s.pop2();

    return 0;
}