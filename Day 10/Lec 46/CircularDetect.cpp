#include "Node.cpp"

bool isLoop(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp == head)
        {
            return 0;
        }
        temp = temp->next;
    }
    return 1;
}

int main()
{
    Node *head = new Node(0);
    Node *node1 = new Node(10);
    Node *node2 = new Node(20);
    Node *node3 = new Node(30);
    Node *node4 = new Node(40);
    Node *node5 = new Node(50);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = head;

    if (isLoop(head))
    {
        cout << "Circular" << endl;
    }
    else
    {
        cout << "Not" << endl;
    }

    return 0;
}