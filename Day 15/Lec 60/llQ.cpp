#include "Node.cpp"

class Queue
{
    Node *head, *rear, *front;

public:
    Queue()
    {
        head = new Node(-1);
        rear = head;
        front = head;
    }

    bool isEmpty()
    {
        if (front == head)
        {
            return 1;
        }
        return 0;
    }

    void push(int x)
    {
        rear->next = new Node(x);
        rear = rear->next;
        if (front == head)
        {
            front = rear;
        }

        cout << front->data << "front" << endl;
        cout << rear->data << "rear" << endl;
    }

    int getFront()
    {
        return front->data;
    }
    int getRear()
    {

        return rear->data;
    }
    void pop()
    {
        if (front == head)
        {
            cout << "Empty" << endl;
            return;
        }
        Node *todel = head->next;
        head->next = front->next;
        front = head->next;
        if (head->next == NULL)
        {
            front = head;
            rear = head;
        }
        delete todel;
    }
};

int main()
{
    Queue q;
    q.pop();
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
    q.pop();
    q.pop();
    cout << q.isEmpty() << endl;
}