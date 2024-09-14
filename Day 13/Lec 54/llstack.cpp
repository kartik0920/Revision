#include "Node.cpp"

void addTail(Node *&head, Node *&tail, int d)
{
    if (tail == NULL)
    {
        head = new Node(d);
        tail = head;
    }
    else
    {
        tail->next = new Node(d);
        tail = tail->next;
    }
}

class Stack
{
public:
    Node *head, *tail;
    Stack()
    {
        this->head = NULL;
        tail = head;
    }

    void push(int d)
    {
        addTail(head, tail, d);
    }
    void peek()
    {
        if (tail == NULL)
        {
            cout << "EMPTY STACK" << endl;
            return;
        }
        cout << tail->data << endl;
    }

    bool isEmpty()
    {
        return tail == NULL ? 1 : 0;
    }

    void pop()
    {
        if (tail == NULL)
        {
            cout << "Empty STACK" << endl;
            return;
        }
        if (head == tail)
        {
            tail = NULL;
            head = NULL;
            return;
        }
        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        tail = temp;
        temp->next = NULL;
    }
};

int main()
{
    Stack s;
    // s.peek();
    s.push(1);
    s.push(2);
    s.peek();
    s.pop();
    s.peek();
    s.pop();
    s.peek();
    return 0;
}