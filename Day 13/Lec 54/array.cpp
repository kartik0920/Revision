#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Stack
{
public:
    int size;
    int *arr;
    int top;
    Stack(int d)
    {
        this->size = d;
        this->arr = new int[d];
        this->top = -1;
    }

    void push(int x)
    {
        if (top < size - 1)
        {
            top++;
            arr[top] = x;
        }
        else
        {
            cout << "OVERFLOW" << endl;
        }
    }

    void pop()
    {
        if (top != 0)
        {
            top--;
        }
        else
        {
            cout << "UNDERFLOW" << endl;
        }
    }

    bool isEmpty()
    {
        return top < 0 ? 1 : 0;
    }

    int peek()
    {
        if (top < 0)
        {
            cout << "Empty" << endl;
            return -1;
        }
        return arr[top];
    }
};
int main()
{
    Stack s(3);
    cout << s.isEmpty() << endl;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.peek() << endl;
    s.pop();
    cout << s.peek() << endl;
    return 0;
}