#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Queue
{
private:
    vector<int> arr;
    int qsize;
    int front, rear;

public:
    Queue(int x)
    {
        this->qsize = x;
        for (int i = 0; i < x; i++)
        {
            arr.push_back(0);
        }
        this->rear = 0;
        this->front = 0;
    }
    bool empty()
    {
        if (rear == front)
        {
            return 1;
        }
        return 0;
    }

    int size()
    {
        return rear - front;
    }

    void push(int x)
    {
        if (rear == qsize)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            arr[rear++] = x;
        }
    }

    void pop()
    {
        if (empty())
        {
            cout << "It is empty" << endl;
        }
        else
        {
            rear--;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
        }
    }
};

int main()
{
    Queue q(5);
    cout << q.empty() << endl;
    q.push(1);
    q.push(1);
    q.pop();
    q.pop();
    q.pop();

    return 0;
}